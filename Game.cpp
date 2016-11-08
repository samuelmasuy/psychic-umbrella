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
    if (map->getCell(characterPositionX, characterPositionY) != "exit") {
      map->print();

      switch (choice = getch()) {
      case KEY_RIGHT:
      case KEY_LEFT:
      case KEY_UP:
      case KEY_DOWN:
        move(choice, characterPositionX, characterPositionY);
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
  if (map->getCell(characterPositionX, characterPositionY) != "exit") {
    map->setCell(characterPositionX, characterPositionY, "empty");
  }
  // might need to put back character original coordinate  + for map
  map->save();
}

void Game::initializeCharacterPositionOnMap() {
  for (int y = 0; y < map->getRows(); y++) {
    for (int x = 0; x < map->getColumns(); x++) {
      if (map->getCell(y, x) == "character") {
        player->setPostionX(x);
        player->setPostionY(y);
      }
    }
  }
}

void Game::move(int choice, int characterPositionX, int characterPositionY) {
  switch (choice) {
  case KEY_RIGHT:
    break;
  case KEY_LEFT:
    break;
  case KEY_UP:
    break;
  case KEY_DOWN:
    break;
  }
}

void Game::openChest() {
}

void Game::fightMonster() {
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
