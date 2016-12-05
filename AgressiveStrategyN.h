#pragma once
#include "StrategyN.h"

class AgressiveStrategyN: public StrategyN {
 public:
  AgressiveStrategyN();
  ~AgressiveStrategyN();
  void execute(GameStateN*, Character*);
  bool moveMonster(Coord2D*, Map*, Character*);
};

