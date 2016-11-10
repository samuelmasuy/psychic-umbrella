/**
 * @file Game.cpp
 * @brief Implementation of the Game walkthought.
 */
#include "Game.h"


void Game::play() {
  CharacterOBS* observerCharacter = new CharacterOBS(character);

  initializeCharacterPositionOnMap();

  int characterPositionX = character->getPostionX();
  int characterPositionY = character->getPostionY();

  char choice;
  string itemType;

  while (true) {
    characterPositionX = character->getPostionX();
    characterPositionY = character->getPostionY();
    // check if character at the exit
    if (map->GetCell(characterPositionX, characterPositionY) != CHAR_EXIT) {
      map->Display();

      cin >> choice;
      switch (choice) {
      case KEY_RIGHT:
        move(characterPositionX + 1, characterPositionY);
        break;
      case KEY_LEFT:
        move(characterPositionX - 1, characterPositionY);
        break;
      case KEY_UP:
        move(characterPositionX, characterPositionY + 1);
        break;
      case KEY_DOWN:
        move(characterPositionX, characterPositionY - 1);
        break;
      case 'c':
        character->playerInfo();
      case 'i':
        character->printEquippedItems();
        character->printBackPackItems();
        map->Display();
      case 'e':
        int level = 1;
        character->setLevel(level);
        map->Display();
      case 'u':

        // unequip from character
        character->unequipItem(itemType);
        map->Display();
      case 'q':
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
  int characterPositionX = character->getPostionX();
  int characterPositionY = character->getPostionY();
  if (map->GetCell(characterPositionX, characterPositionY) != CHAR_EXIT) {
    map->setCell(characterPositionX, characterPositionY, CHAR_EMPTY);
  }
  // might need to put back character original coordinate  + for map
  //map->save();
}

void Game::initializeCharacterPositionOnMap() {
  for (int y = 0; y < map->GetRows(); y++) {
    for (int x = 0; x < map->GetCols(); x++) {
      if (map->GetCell(y, x) == CHAR_PLAYER) {
        character->setPostionX(x);
        character->setPostionY(y);
        return;
      }
    }
  }
}

void Game::move(int old_x, int old_y, int new_x, int new_y) {
  int mapRows = map->GetRows();
  int mapColumns = map->GetCols();
  // Check for valid move
  if (!(new_x >= mapRows || new_x < 0 || new_y >= mapColumns || new_y < 0)) {
    char new_cell_type = map->GetCell(new_x, new_y);
    switch (map->GetCell(new_x, new_y)) {
    case CHAR_WALL:
      break;
    case CHAR_EMPTY:
      // set previous cell to empty
      map->setCell(old_x, old_y, CHAR_EMPTY);
      // set character location to the new cell
      character->setPostionX(new_x);
      character->setPostionY(new_y);
      map->setCell(old_x, old_y, CHAR_PLAYER);
      map->Display();
      break;
    case CHAR_EXIT:
      // set previous cell to empty
      map->setCell(old_x, old_y, CHAR_EMPTY);
      // set character location to the new cell
      character->setPostionX(new_x);
      character->setPostionY(new_y);
      map->Display();
      break;
    case CHAR_CHEST:
      openChest();
      map->Display();
      break;
    }
  }
}

void Game::openChest() {
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
