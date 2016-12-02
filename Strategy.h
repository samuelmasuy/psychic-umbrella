#pragma once

#include <vector>
#include "GameState.h"
#include "Character.h"

using namespace std;

class Strategy {
 public:
  Strategy();
  ~Strategy();
  virtual void execute(GameState*) = 0;
  //void combat(Character* monster);
  //vector<int> checkAdjacentCell(int, int, Map*);
};

