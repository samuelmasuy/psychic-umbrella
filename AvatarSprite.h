#pragma once
#include "Character.h"
#include "StrategyN.h"
class AvatarSprite {
 public:
  AvatarSprite();
  ~AvatarSprite();
  AvatarSprite(Character*, StrategyN*);
  StrategyN* getStrategy();
  void setStrategy(StrategyN*);
  Character* getCharacter();
  void setCharacter(Character*);
  void execute(GameStateN*);
 private:
  Character* c;
  StrategyN* s;


};

