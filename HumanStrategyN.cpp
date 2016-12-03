#include "HumanStrategyN.h"
#include "Monster.h"

HumanStrategyN::HumanStrategyN()
{
}


HumanStrategyN::~HumanStrategyN()
{
}

void HumanStrategyN::execute(GameStateN* inputGameState, Character* c){
	Character* mainCharacter = c;
	Map* map = inputGameState->getMap();
	vector<Character*> monsters = inputGameState->getMonsters();
	vector<Chest*> chests = inputGameState->getChests();

	int xCoordinate;
	int yCoordinate;
	Coord2D *moveTo = new Coord2D(0, 0);

	do {
		cout << "Indicate the x coordinate of where you would like to move to? ";
		cin >> xCoordinate;
		moveTo->x = xCoordinate;
		cout << endl;
		cout << "Indicate the y coordinate of where you woud like to move to? ";
		cin >> yCoordinate;	
		moveTo->y = yCoordinate;
		cout << endl;
		if (moveHuman(moveTo, map, mainCharacter, monsters)) {
			break;
		}

	} while (true);

	
	Character* foundMonster = monsterPresence(mainCharacter, monsters, map);
	Chest* foundChest = chestPresence(mainCharacter, chests, map);

	char action;
	if (foundMonster != nullptr && foundChest != nullptr) {
		cout << "There is a chest and a monster beside you." << endl;
		cout << "Do you want to (a)ttack or open the (c)hest?";
		cin >> action;
		if (action == 'a') {
			cout << "Current hit points for monster " << foundMonster->getHitPoints();
			cout << "Current hit points for character " << mainCharacter->getHitPoints();
			combat(mainCharacter, foundMonster);
			cout << "Current hit points for character " << mainCharacter->getHitPoints();
		} else {
			openChest(mainCharacter, foundChest, map);
		}
	} else if (foundMonster != nullptr){
		cout << "Current hit points for monster " << foundMonster->getHitPoints();
		cout << "Current hit points for character " << mainCharacter->getHitPoints();
		combat(mainCharacter, foundMonster);
		cout << "Current hit points for character " << mainCharacter->getHitPoints();
	}
	else if (foundChest != nullptr){
		openChest(mainCharacter, foundChest, map);
	}
	else
		cout << "Your path is clear.";
	system("pause");
}

bool HumanStrategyN::openChest(Character* c, Chest* chest, Map* m) {
	Item* item = chest->getItem();
	item->printItem();
	cout << "Would you like your character to be equiped with this item? ('y'/'n'): ";
	char choice;
	cin >> choice;
	if (choice == 'y') {
		c = new ItemDecorator(c, item);
		//if (Logger::isOn()) Logger::fout() << "Item Equipped is:" << item->getType() << endl;
		m->setCell(chest->getPositionX(), chest->getPositionY(), CHAR_EMPTY);
		return true;
	}
	return false;
}

Chest* HumanStrategyN::chestPresence(Character* fighter, vector<Chest*> chests, Map* map) {

	Coord2D * locationOfChest = identifyTargetCell(fighter->getPositionX(), fighter->getPositionY(), map, CHAR_CHEST);
	if (locationOfChest == nullptr) {
		return nullptr;
	}
	Chest* foundChest = nullptr;
	for (auto const& chest : chests) {
		if (chest->getPositionX() == locationOfChest->x && chest->getPositionY() == locationOfChest->y) {
			foundChest = chest;
			break;
		}
	}

	return foundChest;
}

Character* HumanStrategyN::monsterPresence(Character* fighter, vector<Character*> monsters, Map* map) {
	Coord2D * locationOfMonster = identifyTargetCell(fighter->getPositionX(), fighter->getPositionY(), map, CHAR_ELF);
	if (locationOfMonster == nullptr) {
		Coord2D * locationOfMonster = identifyTargetCell(fighter->getPositionX(), fighter->getPositionY(), map, CHAR_GOBLIN);
		if (locationOfMonster == nullptr) {
			Coord2D * locationOfMonster = identifyTargetCell(fighter->getPositionX(), fighter->getPositionY(), map, CHAR_LIZARD);
			if (locationOfMonster == nullptr) {
				Coord2D * locationOfMonster = identifyTargetCell(fighter->getPositionX(), fighter->getPositionY(), map, CHAR_SKELETON);
				if (locationOfMonster == nullptr) {
					Coord2D * locationOfMonster = identifyTargetCell(fighter->getPositionX(), fighter->getPositionY(), map, CHAR_VINE);
					if (locationOfMonster == nullptr) {
						Coord2D * locationOfMonster = identifyTargetCell(fighter->getPositionX(), fighter->getPositionY(), map, CHAR_VINE);
						if (locationOfMonster == nullptr) {
							return nullptr;
						}
					}
				}
			}
		}
	}

	Character* foundMonster = nullptr;
	for (auto const& monster : monsters) {
		if (monster->getPositionX() == locationOfMonster->x && monster->getPositionY() == locationOfMonster->y) {
			foundMonster = monster;
			break;
		}
	}
	return foundMonster;
}

bool HumanStrategyN::moveHuman(Coord2D* inputCoord, Map* inputMap, Character* mainPlayer, vector<Character*> monsters){
	if (checkCell(inputCoord, inputMap, CHAR_EMPTY) || checkCell(inputCoord, inputMap, CHAR_ENTRY) || checkCell(inputCoord, inputMap, CHAR_DOOR) || (checkCell(inputCoord, inputMap, CHAR_EXIT) && monsters.size() == 0))
	{
		move(inputCoord, inputMap, mainPlayer);
		return true;
	}

	else{
		cout << "You cannot move to the location specified" <<endl;
		return false;
	}

}

/*
bool HumanStrategyN::combat(Character* fighter, Character* monster){
	Monster *pMonster = (Monster *)&monster;
	int attacksPerRound = fighter->getAttacksPerRound();
	int fighterDamage = fighter->getDamageBonus();
	int monsterDamage = pMonster->getMonsterDamage();
	int result = 0;
	// create a new instance of DiceRoller
	DiceRoller* dice_roller = new DiceRoller();

	try {
		// roll dice with valid query
		result = dice_roller->roll("1d20[+0]");

		fighterDamage += result;

		cout << "  / _ /_  __/_  __/ _ |/ ___/ //_/ /" << endl;
		cout << " / __ |/ /   / / / __ / /__/ ,< /_/ " << endl;
		cout << "/_/ |_/_/   /_/ /_/ |_\\___/_/|_(_)  " << endl << endl;

		for (int i = 1; i < attacksPerRound + 1; i++) {
			cout << "Round " << i << endl;
			cout << "You hit the monster for: " << fighterDamage << endl;
			pMonster->hit(fighterDamage);
			cout << "Monster hits you for: " << monsterDamage << endl;
			fighter->hit(monsterDamage);
			system("pause");
		}
		system("cls");
		monster->setHitPoints(pMonster->getHitPoints());
		cout << "Current hit points for monster " << monster->getHitPoints();
		return true;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return false;
}
*/