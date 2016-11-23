/**
* @file Game.cpp
* @brief Implementation of the Game walkthought.
*/
#include "Game.h"


void Game::play() {
	// set Character observer
	CharacterOBS* observerCharacter = new CharacterOBS(character);
	// set Map observer
	MapOBS* observerMap = new MapOBS(map);

	map->reinitializeMap();
	initializeCharacterPositionOnMap();

	int characterPositionX = character->getPositionX();
	int characterPositionY = character->getPositionY();

	printGameUsage();

	char choice;
	string itemType;
	int itemIndexInBackpack;
	int level = 1;
	while (true) {
		characterPositionX = character->getPositionX();
		characterPositionY = character->getPositionY();
		// check if character at the exit
		if (map->retrieveCell(characterPositionY, characterPositionX) != CHAR_EXIT) {
			cin >> choice;

			switch (choice) {
			case 'd':
				system("cls");
				move(characterPositionX, characterPositionY, characterPositionX + 1, characterPositionY);
				map->print();
				break;
			case 'a':
				system("cls");
				move(characterPositionX, characterPositionY, characterPositionX - 1, characterPositionY);
				map->print();
				break;
			case 'w':
				system("cls");
				move(characterPositionX, characterPositionY, characterPositionX, characterPositionY - 1);
				map->print();
				break;
			case 's':
				system("cls");
				move(characterPositionX, characterPositionY, characterPositionX, characterPositionY + 1);
				map->print();
				break;
			case 'c':
				system("cls");
				character->playerInfo();
				map->print();
				break;
			case 'i':
				system("cls");
				character->printEquippedItems();
				character->printBackPackItems();
				map->print();
				break;
			case 'e':
				system("cls");
				cout << "Enter level: ";
				cin >> level;
				character->setLevel(level);
				map->print();
				break;
			case 'u':
				system("cls");
				cout << "Enter item type to unequip: ";
				cin >> itemType;
				// unequip from character
				character->unequipItem(itemType);
				map->print();
				break;
			case 'x':
				system("cls");
				character->saveCharacter();
				map->print();
				break;
			case 'b':
				system("cls");
				cout << "Here are the items on the backpack" << endl;
				character->printBackPackItems();
				cout << "Enter item # to equip: ";
				cin >> itemIndexInBackpack;
				character->equipFromBackpack(itemIndexInBackpack);
				map->print();
				break;
			case 'h':
				system("cls");
				printGameUsage();
				break;
			case 'q':
				system("cls");
				cout << "Do you want to quit the game? ('y'/'n'): ";
				cin >> choice;
				if (choice == 'y') {
					stop();
					return;
				}
				break;
			default:
				break;
			}
		}
		else {
			stop();
			return;
		}
	}
}

void Game::stop() {
	int characterPositionX = character->getPositionX();
	int characterPositionY = character->getPositionY();
	if (map->retrieveCell(characterPositionX, characterPositionY) != CHAR_EXIT) {
		map->fillCell(characterPositionY, characterPositionX, CHAR_EMPTY);
	}
	system("CLS");
	character->levelUp();
	cout << "Congratulations you finish the level!!" << endl;
	cout << "Here is your character info: " << endl;
	character->playerInfo();
	cout << endl << "Press any key to continue the game." << endl;
	char quit;
	cin >> quit;
	// might need to put back character original coordinate  + for map
	// map->save();
	// character->save();
}

void Game::initializeCharacterPositionOnMap() {
	int ip, jp;
	ip = map->getEntranceRow();
	jp = map->getEntranceColumn();
	map->SetPlayerPos(ip, jp);


	character->setPositionX(jp);
	character->setPositionY(ip);

	map->Display();

	/*
	int ip, jp;
	map->GetPlayerPos(ip, jp);
	character->setPositionX(jp);
	character->setPositionY(ip);
	*/
}
void Game::move(int old_x, int old_y, int new_x, int new_y) {
	int mapRows = map->GetRows();
	int mapColumns = map->GetCols();
	// Check for valid move
	if (!(new_y >= mapRows || new_y < 0 || new_x >= mapColumns || new_x < 0)) {
		char new_cell_type = map->retrieveCell(new_y, new_x);
		// cout << new_cell_type;
		// cout << "old_x " << old_x << "old_y " << old_y << "new_x " << new_x << "new_y " << new_y;
		switch (new_cell_type) {
		case CHAR_WALL:
			cout << "hiting a WALL";
			break;
		case CHAR_EMPTY:
			// set previous cell to empty
			map->fillCell(old_y, old_x, CHAR_EMPTY);
			// set character location to the new cell
			character->setPositionX(new_x);
			character->setPositionY(new_y);
			map->fillCell(new_y, new_x, CHAR_PLAYER);
			break;
		case CHAR_EXIT:
			// set character location to the new cell
			character->setPositionX(new_x);
			character->setPositionY(new_y);
			break;
		case CHAR_DOOR:
			if (openDoor())
			{
				// set previous cell to empty
				map->fillCell(old_y, old_x, CHAR_EMPTY);
				// set character location to the new cell
				character->setPositionX(new_x);
				character->setPositionY(new_y);
				map->fillCell(new_y, new_x, CHAR_PLAYER);

			}
			break;
		case CHAR_CHEST:
			// if the chest was opened, we remove it from the map.
			if (openChest()) {
				// set previous cell to empty
				map->fillCell(old_y, old_x, CHAR_EMPTY);
				// set character location to the new cell
				character->setPositionX(new_x);
				character->setPositionY(new_y);
				map->fillCell(new_y, new_x, CHAR_PLAYER);
			}
			break;
		}
	}
}

bool Game::openChest() {
	// generate a chest.
	ChestDirector* cg = new ChestDirector();
	cg->setChestBuilder(new ChestBuilder());
	cg->makeChest();
	Chest* chest = cg->getChest();
	Item* item = chest->getItem();
	item->printItem();
	cout << "Would you like your character to be equiped with this item? ('y'/'n'): ";
	char choice;
	cin >> choice;
	if (choice == 'y') {
		character->equipItem(item);
		// map->setCell(chest->positionX, chest->postionY, CHAR_EMPTY);
	}
	delete cg;
	return choice == 'y';
}


bool Game::openDoor() {
	// generate a chest.
	DoorDirector* cg = new DoorDirector();
	cg->setDoorBuilder(new DoorBuilder());
	cg->makeDoor();
	Door* door = cg->getDoor();
	cout << "Would you like to open this door? ('y'/'n'): ";
	char choice;
	cin >> choice;
	delete cg;
	return choice == 'y';
}

// void Game::fightMonster() {
//   CharacterDirector* cd = new CharacterDirector();
//   cd->setCharacterBuilder(new ConcreteMonsterBuilder());
//   cd->constructCharacter();
//   Character* monster = cg->getCharacter();
//   monster->print();
//   delete cd;
// }

void Game::setMap(Map* n_map) {
	map = n_map;
}
void Game::setCharacter(Character* n_character) {
	character = n_character;
}
Map* Game::getMap() {
	return map;
}
Character* Game::getCharacter() {
	return character;
}

void Game::printGameUsage() {
	cout << "Use w, a, s, d to move your character." << endl;
	cout << "Use c to display the character statistics." << endl;
	cout << "Use i to display the items on the character." << endl;
	cout << "Use u to unequip an item from the character." << endl;
	cout << "Use e to change the level of the character." << endl;
	cout << "Use x to save your character." << endl;
	cout << "Use b to equip your character with an item in the backpack." << endl;
	cout << "Use h to display this help menu." << endl;
}
