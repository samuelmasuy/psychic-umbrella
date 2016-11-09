/**
 * @file Game.cpp
 * @brief Implementation of the Game walkthought.
 */
#include "Game.h"

void Game::play() {
  character->attachCharacterObserver(this);

  initializeCharacterPositionOnMap();

  int characterPositionX = character->getPostionX();
  int characterPositionY = character->getPostionY();

  int choice;

  while (true) {
    characterPositionX = character->getPostionX();
    characterPositionY = character->getPostionY();
    // check if character at the exit
    if (map->getCell(characterPositionX, characterPositionY) != CHAR_EXIT) {
      map->print();

      switch (choice = getch()) {
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
      case 'q':
        cout << "Do you want to quit the game? ('y'/'n'): " << endl;
        if ((choice = getch()) == 'y') {
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
  if (map->getCell(characterPositionX, characterPositionY) != CHAR_EXIT) {
    map->setCell(characterPositionX, characterPositionY, CHAR_EMPTY);
  }
  // might need to put back character original coordinate  + for map
  map->save();
}

void Game::initializeCharacterPositionOnMap() {
  for (int y = 0; y < map->getRows(); y++) {
    for (int x = 0; x < map->getColumns(); x++) {
      if (map->getCell(y, x) == CHAR_PLAYER) {
        player->setPostionX(x);
        player->setPostionY(y);
        return;
      }
    }
  }
}

void Game::move(int old_x, int old_y, int new_x, int new_y) {
  int mapRows = map->getRows();
  int mapColumns = map->getColumns();
  // Check for valid move
  if (!(new_x >= mapRows || new_x < 0 || new_y >= mapColumns || new_y < 0)) {
    char new_cell_type = map->getCell(new_x, new_y)
    switch (map->getCell(new_x, new_y)) {
    case WALL:
      break;
    case CHAR_EMPTY:
      // set previous cell to empty
      map->setCell(old_x, old_y, CHAR_EMPTY);
      // set character location to the new cell
      character->setPostionX(new_x);
      character->setPostionY(new_y);
      map->setCell(old_x, old_y, CHAR_PLAYER);
      break;
    case CHAR_EXIT:
      // set previous cell to empty
      map->setCell(old_x, old_y, CHAR_EMPTY);
      // set character location to the new cell
      character->setPostionX(new_x);
      character->setPostionY(new_y);
      break;
    case CHAR_CHEST:
      openChest();
      break;
    case CHAR_MONSTER:
      fightMonster();
      break;
    }
  }
}

void Game::openChest() {
  ChestDirector* cg = new ChestDirector();
  cg->setChestBuilder(new ConcreteChestBuilder());
  cg->constructChest();
  Chest* chest = cg->getChest();
  Item* item = chest->getItem();
  item->print();
  cout << "Would you like your character to be equiped with this item? ('y'/'n'): " << endl;
  if ((choice = getch()) == 'y') {
    character->equipItem(item);
    map->setCell(chest->positionX, chest->postionY, CHAR_EMPTY);
  }
  delete cg;
}

void Game::fightMonster() {
  CharacterDirector* cd = new CharacterDirector();
  cd->setCharacterBuilder(new ConcreteMonsterBuilder());
  cd->constructCharacter();
  Character* monster = cg->getCharacter();
  monster->print();
  delete cd;
}

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
