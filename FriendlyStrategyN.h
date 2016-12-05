#pragma once
#include "StrategyN.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "Logger.h"

class FriendlyStrategyN : public StrategyN {
 public:
  FriendlyStrategyN();
  ~FriendlyStrategyN();
  void execute(GameStateN*, Character*);
  bool moveMonster(Coord2D*, Map*, Character*);
};
