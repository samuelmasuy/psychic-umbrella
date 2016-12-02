#pragma once
#include <iostream>
#include "Strategy.h"


using namespace std;

class FriendlyStrategy : public Strategy {
 public:
  FriendlyStrategy();
  ~FriendlyStrategy();
  void execute(GameState*);
};
