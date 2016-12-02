#pragma once
#include <iostream>

#include "Strategy.h"
#include "Map.h"
#include "GameState.h"

using namespace std;

class HumanStrategy : public Strategy {
 public:
  HumanStrategy();
  ~HumanStrategy();
  void execute(GameState*);
};
