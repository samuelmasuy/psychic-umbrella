#pragma once

#include "Strategy.h"
#include <iostream>

using namespace std;

class AggressiveStrategy : public Strategy {
 public:
  AggressiveStrategy();
  ~AggressiveStrategy();
  void execute(GameState*);
};
