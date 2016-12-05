#include "HumanStrategyN.h"
#include "Monster.h"

HumanStrategyN::HumanStrategyN() {
}


HumanStrategyN::~HumanStrategyN() {
}

void HumanStrategyN::execute(GameStateN* inputGameState, Character* c) {
  Character* mainCharacter = c;
  Map* map = inputGameState->getMap();
  vector<Character*> monsters = inputGameState->getMonsters();
  vector<Chest*> chests = inputGameState->getChests();

  int xCoordinate;
  int yCoordinate;
  Coord2D *moveTo = new Coord2D(0, 0);

  do {
    xCoordinate = validate_this_choice(0, 80, "x");
    moveTo->x = xCoordinate;
    cout << endl;
    yCoordinate = validate_this_choice(0, 80, "y");
    moveTo->y = yCoordinate;
    cout << endl;
    if (moveHuman(moveTo, map, mainCharacter, monsters)) {
      if (Logger::isOn())Logger::fout() << "Position: " << mainCharacter->getCharacterType() << " has moved: " << xCoordinate << "," << yCoordinate << endl;
      break;
    }

  } while (true);

  screen::setCursorPosition(screen::COORD_INI_GAME_SCREEN);
  screen::clsGame();
  map->print();
  screen::setCursorPosition(screen::COORD_INI_OBSERVER_SCREEN);
  screen::clsObserver();

  Character* foundMonster = monsterPresence(mainCharacter, monsters, map);
  Chest* foundChest = chestPresence(mainCharacter, chests, map);

  char action;
  if (foundMonster != nullptr && foundChest != nullptr) {
    cout << "There is a chest and a monster beside you." << endl;
    if (Logger::isOn())Logger::fout() << "Player has found a chest and a monster beside them:" << endl;
    cout << "Do you want to (a)ttack or open the (c)hest?";
    cin >> action;
    if (action == 'a') {
      if (AttLogger::isOn()) AttLogger::fout() << "Monster Found" << endl;
      cout << "Current hit points for monster " << foundMonster->getHitPoints() << endl;
      if (AttLogger::isOn()) AttLogger::fout() << "Current hit points for monster:" << foundMonster->getHitPoints() << endl;
      cout << "Current hit points for character " << mainCharacter->getHitPoints();
      if (AttLogger::isOn()) AttLogger::fout() << "Current hit points for Player:" << mainCharacter->getHitPoints() << endl;
      combat(mainCharacter, foundMonster);
      cout << "Current hit points for monster " << foundMonster->getHitPoints() << endl;
      if (AttLogger::isOn()) AttLogger::fout() << "Current hit points for monster:" << foundMonster->getHitPoints() << endl;
      cout << "Current hit points for character " << mainCharacter->getHitPoints();
      if (AttLogger::isOn()) AttLogger::fout() << "Current hit points for Player:" << mainCharacter->getHitPoints() << endl;
    } else {
      openChest(mainCharacter, foundChest, map);
      if (Logger::isOn()) Logger::fout() << "Chest Found" << endl;
    }
  } else if (foundMonster != nullptr) {
    cout << "There is a monster beside you." << endl;
    cout << "Do you want to (a)ttack or do (n)othing?";
    cin >> action;
    if (action == 'a') {
      cout << "Current hit points for monster " << foundMonster->getHitPoints() << endl;
      if (AttLogger::isOn()) AttLogger::fout() << "Current hit points for monster:" << foundMonster->getHitPoints() << endl;
      cout << "Current hit points for character " << mainCharacter->getHitPoints();
      if (AttLogger::isOn()) AttLogger::fout() << "Current hit points for Player:" << mainCharacter->getHitPoints() << endl;
      combat(mainCharacter, foundMonster);
      if (AttLogger::isOn()) AttLogger::fout() << "Current hit points for monster:" << foundMonster->getHitPoints() << endl;
      cout << "Current hit points for monster " << foundMonster->getHitPoints() << endl;
      if (AttLogger::isOn()) AttLogger::fout() << "Current hit points for Player:" << mainCharacter->getHitPoints() << endl;
      cout << "Current hit points for character " << mainCharacter->getHitPoints() << endl;
      if (foundMonster->getHitPoints() <= 0) {
        cout << "The monster " << foundMonster->getCharacterType() << " died!!!" << endl;
        map->fillCell(foundMonster->getPositionX(), foundMonster->getPositionY(), CHAR_EMPTY);
      }
    }
    if (AttLogger::isOn()) AttLogger::fout() << "Current hit points for Player:" << mainCharacter->getHitPoints() << endl;
  } else if (foundChest != nullptr) {
    cout << "Do you want to (o)pen the chest or do (n)othing?";
    cin >> action;
    if (action == 'o') {
      openChest(mainCharacter, foundChest, map);
    }
  } else {
    cout << "Your path is clear.";
  }
  system("pause");
}

bool HumanStrategyN::openChest(Character* c, Chest* chest, Map* m) {
  if (Logger::isOn()) Logger::fout() << "Chest Found" << endl;
  Item* item = chest->getItem();
  item->printItem();
  cout << "Would you like your character to be equiped with this item? ('y'/'n'): ";
  char choice;
  cin >> choice;
  if (choice == 'y') {
    c = new ItemDecorator(c, item);
    if (Logger::isOn()) Logger::fout() << "Item Equipped is:" << item->getType() << endl;
    m->setCell(chest->getPositionY(), chest->getPositionX(), CHAR_EMPTY);
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
    if (chest->getPositionY() == locationOfChest->x && chest->getPositionX() == locationOfChest->y) {
      foundChest = chest;
      break;
    }
  }

  return foundChest;
}

Character* HumanStrategyN::monsterPresence(Character* fighter, vector<Character*> monsters, Map* map) {
  Coord2D * locationOfMonster = nullptr;
  locationOfMonster = identifyTargetCell(fighter->getPositionX(), fighter->getPositionY(), map, CHAR_ELF);
  if (locationOfMonster == nullptr) {
    locationOfMonster = identifyTargetCell(fighter->getPositionX(), fighter->getPositionY(), map, CHAR_GOBLIN);
    if (locationOfMonster == nullptr) {
      locationOfMonster = identifyTargetCell(fighter->getPositionX(), fighter->getPositionY(), map, CHAR_LIZARD);
      if (locationOfMonster == nullptr) {
        locationOfMonster = identifyTargetCell(fighter->getPositionX(), fighter->getPositionY(), map, CHAR_SKELETON);
        if (locationOfMonster == nullptr) {
          locationOfMonster = identifyTargetCell(fighter->getPositionX(), fighter->getPositionY(), map, CHAR_VINE);
          if (locationOfMonster == nullptr) {
            locationOfMonster = identifyTargetCell(fighter->getPositionX(), fighter->getPositionY(), map, CHAR_VINE);
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

bool HumanStrategyN::moveHuman(Coord2D* inputCoord, Map* inputMap, Character* mainPlayer, vector<Character*> monsters) {
  if (checkCell(inputCoord, inputMap, CHAR_ENTRY) || checkCell(inputCoord, inputMap, CHAR_EMPTY) || checkCell(inputCoord, inputMap, CHAR_DOOR) || (monsters.size() == 0 && checkCell(inputCoord, inputMap, CHAR_EXIT))) {
    move(inputCoord, inputMap, mainPlayer, CHAR_PLAYER);
    return true;
  } else {
    cout << "You cannot move to the location specified" <<endl;
    return false;
  }

}

int HumanStrategyN::validate_this_choice(int min, int max, string coord) {
  while (true) {
    cout << "Indicate the " << coord << " coordinate of where you would like to move to: ";
    string s;
    getline(cin, s);
    char *endp = 0;
    int ret = strtol(s.c_str(), &endp, 10);
    if (endp != s.c_str() && !*endp && ret >= min && ret <= max) {
      return ret;
    }
    cout << "Invalid choice." << endl;
    screen::setCursorPosition(screen::COORD_INI_OBSERVER_SCREEN);
    screen::clsObserver();
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
