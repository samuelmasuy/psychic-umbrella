#include "HumanStrategyN.h"
#include "Monster.h"

HumanStrategyN::HumanStrategyN()
{
}


HumanStrategyN::~HumanStrategyN()
{
}

void HumanStrategyN::execute(GameStateN* inputGameState){
	Character* mainCharacter = inputGameState->getMainCharacter();
	Map* map = inputGameState->getMap();
	vector<Character*> monsters = inputGameState->getMonsters();
	vector<Chest*> chests = inputGameState->getChests();

	int xCoordinate;
	int yCoordinate;

	do {
		cout << "Indicate the x coordiante of where you would like to move to? ";
		cin >> xCoordinate;
		cout << endl;
		cout << "Indicate the y coordinate of where you woud like to move to? ";
		cin >> yCoordinate;	
		cout << endl;
		if (map->ValidPos(xCoordinate, yCoordinate)) {
			break;
		}
		cout << "Invalid coordinate, please try again.";
	} while (true);

	mainCharacter->setPositionX(xCoordinate);
	mainCharacter->setPositionY(yCoordinate);

	//openChest(chests, mainCharacter, map);
	cout << "Current hit points for character " << mainCharacter->getHitPoints();
	combat(mainCharacter, monsters, map);
	cout << "Current hit points for character " << mainCharacter->getHitPoints();
}

bool HumanStrategyN::openChest(vector<Chest*> inputChests, Character* mainPlayer, Map* inputMap) {
	Coord2D * locationOfChest = identifyTargetCell(mainPlayer->getPositionX(), mainPlayer->getPositionY(), inputMap, CHAR_CHEST);
	if (locationOfChest != nullptr) {
		Chest* foundChest = nullptr;
		for (auto const& chest : inputChests) {
			if (chest->getPositionX() == locationOfChest->x && chest->getPositionY() == locationOfChest->y) {
				foundChest = chest;
				break;
			}
		}
		Item* item = foundChest->getItem();
		item->printItem();
		cout << "Would you like your character to be equiped with this item? ('y'/'n'): ";
		char choice;
		cin >> choice;
		if (choice == 'y') {
			mainPlayer = new ItemDecorator(mainPlayer, item);
			//if (Logger::isOn()) Logger::fout() << "Item Equipped is:" << item->getType() << endl;
			inputMap->setCell(locationOfChest->x, locationOfChest->y, CHAR_EMPTY);
			return true;
		}
	}
	return false;
}
 
bool HumanStrategyN::combat(Character* fighter, vector<Character*> monsters, Map* map){
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
							return false;
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
	Monster *pMonster = (Monster *)&foundMonster;
	int attacksPerRound = fighter->getAttacksPerRound();
	int fighterDamage = fighter->getDamageBonus();
	int monsterDamage = pMonster->getMonsterDamage();
	int result = 0;

	// create a new instance of DiceRoller
	DiceRoller* dice_roller = new DiceRoller();

	cout << "Current hit points for monster " << foundMonster->getHitPoints();
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
		foundMonster->setHitPoints(pMonster->getHitPoints());
		cout << "Current hit points for monster " << foundMonster->getHitPoints();
		return true;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return false;
}