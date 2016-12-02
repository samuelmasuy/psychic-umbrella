#pragma once
#include <vector>
#include "Map.h"
#include "Character.h"

using namespace std;

class GameState {
 public:
  GameState() {}
  ~GameState() {}
  GameState(Character*, vector<Character*>, Map*);
  void setMap(Map*);
  Map* getMap();
  void setMainCharacter(Character*);
  Character* getMainCharacter();
  void setMonsters(vector<Character*>);
  vector<Character*> getMonsters();
 private:
  Character* mainCharacter;
  vector<Character*> monsters;
  Map* map;
};
