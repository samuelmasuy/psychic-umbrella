/**
 * @file Game.cpp
 * @brief Implementation of the Game walkthought.
 */
#include "Game.h"

void Game::play() {
  CharacterOBS* observerCharacter = new CharacterOBS(character);

  map->reinitializeMap();
  initializeCharacterPositionOnMap();

  int characterPositionX = character->getPositionX();
  int characterPositionY = character->getPositionY();

  printGameUsage();

  char choice;
  string itemType;
  int level = 1;
  while (true) {
    characterPositionX = character->getPositionX();
    characterPositionY = character->getPositionY();
    // check if character at the exit
    if (map->retrieveCell(characterPositionY, characterPositionX) != CHAR_EXIT) {
      cin >> choice;

      switch (choice) {
      case 'd':
        //clear_screen();
		  system("cls");
        move(characterPositionX, characterPositionY, characterPositionX + 1, characterPositionY);
        map->print();
        break;
      case 'a':
       // clear_screen();
		system("cls");
        move(characterPositionX, characterPositionY, characterPositionX - 1, characterPositionY);
        map->print();
        break;
      case 'w':
        //clear_screen();
		system("cls");
        move(characterPositionX, characterPositionY, characterPositionX, characterPositionY - 1);
        map->print();
        break;
      case 's':
       // clear_screen();
		  system("cls");
        move(characterPositionX, characterPositionY, characterPositionX, characterPositionY + 1);
        map->print();
        break;
      case 'c':
       // clear_screen();
		  system("cls");
        character->playerInfo();
        map->print();
        break;
      case 'i':
        //clear_screen();
		  system("cls");
        character->printEquippedItems();
        character->printBackPackItems();
        map->print();
        break;
      case 'e':
       // clear_screen();
		  system("cls");
        cout << "Enter level: ";
        cin >> level;
        character->setLevel(level);
        map->print();
        break;
      case 'u':
        //clear_screen();
		  system("cls");
        cout << "Enter item type to unequip: ";
        cin >> itemType;
        // unequip from character
        character->unequipItem(itemType);
        map->print();
        break;
      case 'h':
       // clear_screen();
		  system("cls");
        printGameUsage();
		break;
      case 'q':
       //clear_screen();
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
    } else {
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
  cout << endl << "Press any key to quit the game." << endl;
  char quit;
  cin >> quit
  // might need to put back character original coordinate  + for map
  // map->save();
}

void Game::initializeCharacterPositionOnMap() {
  int ip, jp;
  map->GetPlayerPos(ip, jp);
  character->setPositionX(jp);
  character->setPositionY(ip);
}

void Game::move(int old_x, int old_y, int new_x, int new_y) {
  int mapRows = map->GetRows();
  int mapColumns = map->GetCols();
  // Check for valid move
  if (!(new_x >= mapRows || new_x < 0 || new_y >= mapColumns || new_y < 0)) {
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
    case CHAR_CHEST:
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
  cout << "Use h to display this help menu." << endl;
}
