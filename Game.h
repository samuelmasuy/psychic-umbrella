#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include <Item.h>
#include <Character.h>
#include <Map.h>
#include <CharacterBuilder.h>
#include <ChestBuilder.h>

using namespace std;

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
  void move(int, int, int);
  void openChest();
  void fightMonster();
  ItemDirector* id;
};
