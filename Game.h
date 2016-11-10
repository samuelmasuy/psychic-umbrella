/**
 * @file Game.h
 * @brief Definition of the Game walkthought.
 */
#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Item.h"
#include "Character.h"
#include "Map.h"
#include "ChestBuilder.h"
#include "CharacterOBS.h"
#include "ChestDirector.h"

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class Game {
 public:
  void play();
  void stop();

  void setMap(Map*);
  void setCharacter(Character*);
  Map* getMap();
  Character* getCharacter();
 private:
  Map* map;
  Character* character;
  void initializeCharacterPositionOnMap();
  void move(int, int, int, int);
  void openChest();
  void fightMonster();
  ItemDirector* id;
};
