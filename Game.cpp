/**
* @file Game.cpp
* @brief Implementation of the Game walkthought.
*/
#include "Game.h"

void Game::play() {
	// set Character observer
	CharacterOBS* observerCharacter = new CharacterOBS(character);
	// set Map observer
	MapOBS* observerMap = new MapOBS(_map);

	MonsterDirector* md = new MonsterDirector();

	vector<Character*> monsters;

	vector<Chest*> chests = createChestsFromMap();

	cout << "equiped items in game";
	vector<Item*> equiped = getCharacterEquipedItems();
	for (int i = 0; i <= equiped.size(); i++)
	{
		equiped[i]->printItem();
	}

	Character* monster = NULL;

	MonsterBuilder* monsterBuilder = NULL;

	for (int i = 0; i < 6; i++) {
		int x = 0;
		int y = 0;
		bool found = _map->FindItem('1', x, y);
		if (found) {
			switch (i)
			{
			case 1:
				monsterBuilder = new ElfBuilder();
				md->setMonsterBuilder(monsterBuilder);
				md->constructMonster();
				monster = md->getMonster();
				monster->setPositionX(x);
				monster->setPositionY(y);
				monsters.push_back(monster);
				delete monsterBuilder;
				break;
			case 2:
				monsterBuilder = new GoblinBuilder();
				md->setMonsterBuilder(monsterBuilder);
				md->constructMonster();
				monster = md->getMonster();
				monster->setPositionX(x);
				monster->setPositionY(y);
				monsters.push_back(monster);
				delete monsterBuilder;
				break;
			case 3:
				monsterBuilder = new LizardBuilder();
				md->setMonsterBuilder(monsterBuilder);
				md->constructMonster();
				monster = md->getMonster();
				monster->setPositionX(x);
				monster->setPositionY(y);
				monsters.push_back(monster);
				delete monsterBuilder;
				break;
			case 4:
				monsterBuilder = new MedusaBuilder();
				md->setMonsterBuilder(monsterBuilder);
				md->constructMonster();
				monster = md->getMonster();
				monster->setPositionX(x);
				monster->setPositionY(y);
				monsters.push_back(monster);
				delete monsterBuilder;
				break;
			case 5:
				monsterBuilder = new SkeletonBuilder();
				md->setMonsterBuilder(monsterBuilder);
				md->constructMonster();
				monster = md->getMonster();
				monster->setPositionX(x);
				monster->setPositionY(y);
				monsters.push_back(monster);
				delete monsterBuilder;
				break;
			case 6:
				monsterBuilder = new VineBuilder();
				md->setMonsterBuilder(monsterBuilder);
				md->constructMonster();
				monster = md->getMonster();
				monster->setPositionX(x);
				monster->setPositionY(y);
				monsters.push_back(monster);
				delete monsterBuilder;
				break;
			}


		}
	}
		
	delete md;

	_map->reinitializeMap();
	initializeCharacterPositionOnMap();

	int characterPositionX = character->getPositionX();
	int characterPositionY = character->getPositionY();
	enemiesDefeated = false;
	enemiesDefeated = (_map->countMonsters() == 0);

	printGameUsage();

	Item* backpackItem = nullptr;
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
				game->printGameUsage();
				break;
			case 'a':
				system("cls");
				move(characterPositionX, characterPositionY, characterPositionX - 1, characterPositionY);
				_map->print();
				game->printGameUsage();
				break;
			case 'w':
				system("cls");
				move(characterPositionX, characterPositionY, characterPositionX, characterPositionY - 1);
				_map->print();
				game->printGameUsage();
				break;
			case 's':
				system("cls");
				move(characterPositionX, characterPositionY, characterPositionX, characterPositionY + 1);
				_map->print();
				game->printGameUsage();
				break;
			case 'c':
				system("cls");
				character->playerInfo();
				_map->print();
				game->printGameUsage();
				break;
			case 'i':
				system("cls");
				character->printEquippedItems();
				character->printBackPackItems();
				_map->print();
				game->printGameUsage();
				break;
			case 'e':
				system("cls");
				cout << "Enter level: ";
				cin >> level;
				character->setLevel(level);
				_map->print();
				game->printGameUsage();
				break;
			case 'u':
				system("cls");
				cout << "Enter item type to unequip: ";
				cin >> itemType;
				// unequip from character
				character->unEquip(itemType);
				_map->print();
				game->printGameUsage();
				break;
			case 'x':
				system("cls");
				saveCharacter();
				_map->print();
				game->printGameUsage();
				break;
			case 'l':
				system("cls");
				loadCharacter();
				_map->print();
				game->printGameUsage();
				break;
			case 'b':
				system("cls");
				cout << "Here are the items on the backpack" << endl;
				character->printBackPackItems();
				cout << "Enter item # to equip: ";
				cin >> itemIndexInBackpack;
				backpackItem = character->getBackPack().getItemAtIndex(itemIndexInBackpack);
				character = new ItemDecorator(character, backpackItem);
				_map->print();
				game->printGameUsage();
				break;
			case 'h':
				system("cls");
				printGameUsage();
				break;
			case '1':
				system("cls");
				Characterlog();
				_map->print();
				game->printGameUsage();
				break;
			case '2':
				system("cls");
				Gamelog();
				_map->print();
				game->printGameUsage();
				break;
			case '3':
				system("cls");
				AttackLog();
				_map->print();
				game->printGameUsage();
				break;
			case '4':
				system("cls");
				DiceLog();
				_map->print();
				game->printGameUsage();
				break;
			case '5':
				system("cls");
				AllLogs();
				_map->print();
				game->printGameUsage();
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
	vector<Item*> equipment = getCharacterEquipedItems();
	


	cout << "Enter name of file being saved: ";
	cin >> saveFile;



	ofstream ofs(saveFile);
	ofs << "CharFile" << endl;	//define type of save file
	ofs << character->getCharacterType() << endl;
	ofs << character->getLevel() << endl;
	ofs << character->getHitPoints() << endl;
	for (int i = 0; i < 6; i++)
		ofs << character->getAbilityScore(i) << endl;
	//ofs << character->armorModifier() << endl;
	//ofs << character->getDamageBonus() << endl;

	ofs << equipment.size() << endl;
	

	for (int i = 0; i < equipment.size(); i++)
	{

		type = equipment[i]->getType();
		if (type != "")
		{
			ofs << equipment[i]->getType() << endl;
			ofs << equipment[i]->getInfluences().size() << endl;
			for (int j = 0; j < equipment[i]->getInfluences().size(); j++)
			{
				ofs << equipment[i]->getInfluences().at(0).getType() << endl;
				ofs << equipment[i]->getInfluences().at(0).getBonus() << endl;
			}
		}

	}
	
	if (character->getBackPack().getSize() != 0){
		ofs << character->getBackPack().getSize() << endl;
		for (int i = 0; i < character->getBackPack().getSize(); i++)
		{

			ofs << character->getBackPack().getItems().at(i)->getType() << endl;
			ofs << character->getBackPack().getItems()[i]->getInfluences().size() << endl;
			for (int j = 0; j < character->getBackPack().getItems()[i]->getInfluences().size(); j++)
			{
				ofs << character->getBackPack().getItems()[i]->getInfluences().at(j).getType() << endl;
				ofs << character->getBackPack().getItems()[i]->getInfluences().at(j).getBonus() << endl;
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
	int currentHitPoints;
	int level;
	int ability;
	bool chooseFileName = false;
	int backpackSize;
	int bonus;
	int size;
	int influenceSize;
	int equippedSize;




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
	character->setLevel(level);
	
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
			Item* itemFromFile;
			Enhancement* itemEnhacement;

			ifs >> type;
			itemFromFile->setType(type);
			ifs >> bonus;

			ifs >> influenceSize;
			for (int j = 0; j < influenceSize; j++)
			{
				ifs >> type;
				ifs >> bonus;
			}
			itemEnhacement = new Enhancement(type, bonus);
			itemFromFile->setInfluences(*itemEnhacement);
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
				character->addToBackpack(myItem);
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
	if (Logger::isOn()) Logger::fout() << "Level finished" << endl;
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

	
	/* Example of how to get elf's x and y position
	int iELF, jELF;
    _map->GetEnemyPos(CHAR_ELF, iELF, jELF);
	now, iELF and jELF hold the elf's x and y position (if there is no elf on the map x and y will be equal to -1)
	*/
}
void Game::move(int old_x, int old_y, int new_x, int new_y) {
	int mapRows = _map->GetRows();
	int mapColumns = _map->GetCols();
	// Check for valid move
	if (!(new_y >= mapRows || new_y < 0 || new_x >= mapColumns || new_x < 0)) {
		if (Logger::isOn())Logger::fout() << "Position: " << character->getCharacterType() << " has moved: " << character->getPositionY() + 1 << "," << character->getPositionX() + 1 << endl;
		char new_cell_type = _map->retrieveCell(new_y, new_x);
		
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
			if (enemiesDefeated)
			{
				// set character location to the new cell
				character->setPositionX(new_x);
				character->setPositionY(new_y);
			}
			else
			{
				cout << "Cannot exit the map until all Monsters have been defeated" << endl;
			}

			break;
		case CHAR_DOOR:
			if (Logger::isOn()) Logger::fout() << "Player encountered a Door" << endl;
			if (openDoor())
			{
				if (Logger::isOn()) Logger::fout() << "Player has opened a door" << endl;
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
			if (Logger::isOn()) Logger::fout() << "Player moved on a chest" << endl;
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
	if (Logger::isOn()) Logger::fout() << "Player opened Chest" << endl;
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
		character = new ItemDecorator(character, item);
		if (Logger::isOn()) Logger::fout() << "Item Equipped is:" << item->getType() << endl;
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
	cout << "Use 1 to toggle on/off the Character Log" << endl;
	cout << "Use 2 to toggle on/off the Game Log." << endl;
	cout << "Use 3 to toggle on/off the Attack Log." << endl;
	cout << "Use 4 to toggle on/off the Dice log." << endl;
	cout << "Use 5 to toggle on/off All the logs" << endl;
}


vector<Item*> Game::getCharacterEquipedItems() {
	Item* i = nullptr;
	vector<Item*> equipedItems;
	if (character->isEquiped("ring")) {
		i = character->retrieveItem("ring");
		equipedItems.push_back(i);
	}
	if (character->isEquiped("belt")) {
		i = character->retrieveItem("belt");
		equipedItems.push_back(i);
	}
	if (character->isEquiped("boots")) {
		i = character->retrieveItem("boots");
		equipedItems.push_back(i);
	}
	if (character->isEquiped("helmet")) {
		i = character->retrieveItem("helmet");
		equipedItems.push_back(i);
	}
	if (character->isEquiped("shield")) {
		i = character->retrieveItem("shield");
		equipedItems.push_back(i);
	}
	if (character->isEquiped("boots")) {
		i = character->retrieveItem("boots");
		equipedItems.push_back(i);
	}
	if (character->isEquiped("weapon")) {
		i = character->retrieveItem("weapon");
		equipedItems.push_back(i);
	}
	if (character->isEquiped("armor")) {
		i = character->retrieveItem("armor");
		equipedItems.push_back(i);
	}
	delete i;
	return equipedItems;
}

vector<Chest*> Game::createChestsFromMap() {
	// map get  all chests position
	int chest_size = 5; //sizeof
	vector<Chest*> chests;

	ChestDirector* cg = new ChestDirector();
	Chest* mapChest = nullptr;

	for (int i = 0; i < chest_size; i++) {
		cg->setChestBuilder(new ChestBuilder());
		cg->makeChest();
		Chest* mapChest = cg->getChest();
		mapChest->setPositionX(i);
		mapChest->setPositionY(i);
		chests.push_back(mapChest);
	}
	delete mapChest;
	delete cg;
	return chests;
}