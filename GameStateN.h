#pragma once

#include "Character.h"
#include "Map.h"
#include "Chest.h"
#include <vector>


class GameStateN {
 public:
  GameStateN();
  ~GameStateN();
  GameStateN(Character*, vector<Character*>, Map*, vector<Chest*>);
  void setMap(Map*);
  Map* getMap();
  void setMainCharacter(Character* inputMainCharacter);
  Character* getMainCharacter();
  void setMonsters(vector<Character*>);
  vector<Character*> getMonsters();
  void setChests(vector<Chest*>);
  vector<Chest*> getChests();
 private:
  Character* mainCharacter;
  vector<Character*> monsters;
  Map* map;
  vector<Chest*> chests;
};
