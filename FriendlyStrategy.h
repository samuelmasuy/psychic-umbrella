#pragma once
#include "GameState.h"
#include "Strategy.h"
#include "Map.h"

using namespace std;

class FriendlyStrategy : public Strategy {
 public:
  FriendlyStrategy();
  ~FriendlyStrategy();
  void execute(GameState*);
};
