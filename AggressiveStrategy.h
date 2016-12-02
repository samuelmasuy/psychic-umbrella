#pragma once

#include "Strategy.h"
#include "GameState.h"

using namespace std;

class AggressiveStrategy : public Strategy {
 public:
  AggressiveStrategy();
  ~AggressiveStrategy();
  void execute(GameState*);
};
