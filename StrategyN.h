#pragma once
#include "GameStateN.h"
#include "ItemDecorator.h"
#include "DiceRoller.h"
#include "Monster.h"
#include "Screen.h"
#include "Logger.h"



class StrategyN {
 public:
  StrategyN();
  ~StrategyN();
  virtual void execute(GameStateN*, Character*) = 0;
  bool checkCell(Coord2D*, Map*, char);
  Coord2D* identifyTargetCell(int, int, Map*, char);
  void move(Coord2D*, Map*, Character*, char);
  bool combat(Character*, Character*);
};

