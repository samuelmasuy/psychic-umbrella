/**
* @file Game.cpp
* @brief Implementation of the Game walkthought.
*/
#include <map>
#include "Game.h"


void Game::play() {
	// set Character observer
	CharacterOBS* observerCharacter = new CharacterOBS(character);
	// set Map observer
	MapOBS* observerMap = new MapOBS(_map);

	_map->reinitializeMap();
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
		if (_map->retrieveCell(characterPositionY, characterPositionX) != CHAR_EXIT) {
			cin >> choice;

			switch (choice) {
			case 'd':
				system("cls");
				move(characterPositionX, characterPositionY, characterPositionX + 1, characterPositionY);
				_map->print();
				break;
			case 'a':
				system("cls");
				move(characterPositionX, characterPositionY, characterPositionX - 1, characterPositionY);
				_map->print();
				break;
			case 'w':
				system("cls");
				move(characterPositionX, characterPositionY, characterPositionX, characterPositionY - 1);
				_map->print();
				break;
			case 's':
				system("cls");
				move(characterPositionX, characterPositionY, characterPositionX, characterPositionY + 1);
				_map->print();
				break;
			case 'c':
				system("cls");
				character->playerInfo();
				_map->print();
				break;
			case 'i':
				system("cls");
				character->printEquippedItems();
				character->printBackPackItems();
				_map->print();
				break;
			case 'e':
				system("cls");
				cout << "Enter level: ";
				cin >> level;
				character->setLevel(level);
				_map->print();
				break;
			case 'u':
				system("cls");
				cout << "Enter item type to unequip: ";
				cin >> itemType;
				// unequip from character
				character->unequipItem(itemType);
				_map->print();
				break;
			case 'x':
				system("cls");
				saveCharacter();
				_map->print();
				break;
			case 'l':
				system("cls");
				loadCharacter();
				_map->print();
				break;
			case 'b':
				system("cls");
				cout << "Here are the items on the backpack" << endl;
				character->printBackPackItems();
				cout << "Enter item # to equip: ";
				cin >> itemIndexInBackpack;
				character->equipFromBackpack(itemIndexInBackpack);
				_map->print();
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
void Game::saveCharacter(){
	string type = "";
	string saveFile;
	map<string, Character*> equipedItems;
	equipedItems = character->getEquippedItems();

	
	cout << "Enter name of file being saved: ";
	cin >> saveFile;
	


	ofstream ofs(saveFile);
	ofs << "CharFile" << endl;	//define type of save file
	ofs << character->getCharacterType() << endl;
	ofs << character->getLevel() << endl;
	ofs << character->getHitPoints() << endl;
		for (int i = 0; i < 6; i++)
			ofs <<  character->getAbilityScore(i) << endl;
	//ofs << character->armorModifier() << endl;
	//ofs << character->getDamageBonus() << endl;

	ofs << equipedItems.size() << endl;
	for (map<string, Character*>::iterator it = equipedItems.begin(); it != equipedItems.end(); ++it) {
		ofs << it->first << "\n";
	}
/*	
	for (int i = 0; i < equipedItems.size(); i++)
	{
		
		type = equipment[i].getType();
		if (type != "")
		{
			ofs << equipment[i].getType() << endl;
			ofs << equipment[i].getInfluences().size() << endl;
			for (int j = 0; j < equipment[i].getInfluences().size(); j++)
			{
				ofs << equipment[i].getInfluences().at(0).getType() << endl;
				ofs << equipment[i].getInfluences().at(0).getBonus() << endl;
			}
		}
		
	}
*/	
	if (character->getBackPack().getSize() != 0){
		ofs << character->getBackPack().getSize() << endl;
		for (int i = 0; i < character->getBackPack().getSize(); i++)
		{
			ofs << character->getBackPack().getItems().at(0).getType() << endl;
			ofs << character->getBackPack().getItems()[i].getInfluences().size() << endl;
			for (int j = 0; j < character->getBackPack().getItems()[i].getInfluences().size(); j++)
			{
				ofs << character->getBackPack().getItems()[i].getInfluences().at(0).getType() << endl;
				ofs << character->getBackPack().getItems()[i].getInfluences().at(0).getBonus() << endl;
			}
		}
	}
	else
		ofs << 0;

	ofs.close();


	
}

void Game::loadCharacter()
{
	string loadFile;
	string Validation;
	string type;
	string characterType;
	string items;
	int currentHitPoints;
	int level;
	int ability;
	bool chooseFileName = false;
	int backpackSize;
	int bonus;
	int size;
	int influenceSize;
	int equippedSize;
	map<string, Character*> equipedItems;


	cout << "Load File: ";
	cin >> loadFile;

	ifstream ifs(loadFile);
	do {
		while (!ifs.good()) {
			cout << "File does not exist, try again: ";
			cin >> loadFile;
			ifs.open(loadFile);
		}
		ifs >> Validation;
		if (Validation == "CharFile")//check if it is an item save file
			chooseFileName = true;
		else {
			ifs.close();
			chooseFileName = false;
			cout << "Incorrect File Loaded, select another File: " << endl;
			cin >> loadFile;
			ifs.open(loadFile);
		}
	} while (chooseFileName == false);

	ifs >> characterType;
	character->setCharacterType(characterType);
	ifs >> level;
	//for (int i = 1; i < level; i++)
//	{
		character->setLevel(level);
//	}
	ifs >> currentHitPoints;
	character->setHitPoints(currentHitPoints);
	
	for (int i = 0; i < 6; i++)
	{
		ifs >> ability;
		character->setAbilityScores(i, ability);
	}
		
	ifs >> equippedSize;
	if (equippedSize > 0)
	{
		for (int i = 0; i < equippedSize; i++)			//save equipped items
		{
			//ifs >> items;
			//equipedItems.insert(items);
		}

	}
	
	ifs >> backpackSize;
	if (backpackSize != 0)
	{
		Item* myItem;
		Enhancement  *myEnhacements;


		for (int i = 0; i < backpackSize; i++)		//save inventory/backpack
		{
			ifs >> type;
			myItem = new Item();
			myItem->setType(type);
			ifs >> influenceSize;
			for (int j = 0; j < influenceSize; j++)
			{
				ifs >> type;
				ifs >> bonus;
				myEnhacements = new Enhancement(type, bonus);
				myItem->setInfluences(*myEnhacements);
				character->addToBackpack(*myItem);
				delete myItem;
				delete myEnhacements;
			}

		}
	}

	ifs.close();

}

void Game::stop() {
	int characterPositionX = character->getPositionX();
	int characterPositionY = character->getPositionY();
	if (_map->retrieveCell(characterPositionX, characterPositionY) != CHAR_EXIT) {
		_map->fillCell(characterPositionY, characterPositionX, CHAR_EMPTY);
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
	// _map->save();
	// character->save();
}

void Game::initializeCharacterPositionOnMap() {
	int ip, jp;
	ip = _map->getEntranceRow();
	jp = _map->getEntranceColumn();
	_map->SetPlayerPos(ip, jp);


	character->setPositionX(jp);
	character->setPositionY(ip);

	_map->Display();

	/*
	int ip, jp;
	_map->GetPlayerPos(ip, jp);
	character->setPositionX(jp);
	character->setPositionY(ip);
	*/
}
void Game::move(int old_x, int old_y, int new_x, int new_y) {
	int mapRows = _map->GetRows();
	int mapColumns = _map->GetCols();
	// Check for valid move
	if (!(new_y >= mapRows || new_y < 0 || new_x >= mapColumns || new_x < 0)) {
		char new_cell_type = _map->retrieveCell(new_y, new_x);
		// cout << new_cell_type;
		// cout << "old_x " << old_x << "old_y " << old_y << "new_x " << new_x << "new_y " << new_y;
		switch (new_cell_type) {
		case CHAR_WALL:
			cout << "hiting a WALL";
			break;
		case CHAR_EMPTY:
			// set previous cell to empty
			_map->fillCell(old_y, old_x, CHAR_EMPTY);
			// set character location to the new cell
			character->setPositionX(new_x);
			character->setPositionY(new_y);
			_map->fillCell(new_y, new_x, CHAR_PLAYER);
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
				_map->fillCell(old_y, old_x, CHAR_EMPTY);
				// set character location to the new cell
				character->setPositionX(new_x);
				character->setPositionY(new_y);
				_map->fillCell(new_y, new_x, CHAR_PLAYER);

			}
			break;
		case CHAR_CHEST:
			// if the chest was opened, we remove it from the map.
			if (openChest()) {
				// set previous cell to empty
				_map->fillCell(old_y, old_x, CHAR_EMPTY);
				// set character location to the new cell
				character->setPositionX(new_x);
				character->setPositionY(new_y);
				_map->fillCell(new_y, new_x, CHAR_PLAYER);
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
		// _map->setCell(chest->positionX, chest->postionY, CHAR_EMPTY);
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
	_map = n_map;
}
void Game::setCharacter(Character* n_character) {
	character = n_character;
}
Map* Game::getMap() {
	return _map;
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
	cout << "Use l to load a character from file" << endl;
	cout << "Use b to equip your character with an item in the backpack." << endl;
	cout << "Use h to display this help menu." << endl;
}
