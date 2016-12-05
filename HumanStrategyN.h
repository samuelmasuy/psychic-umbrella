#pragma once
#include "GameStateN.h"
#include "ItemDecorator.h"
#include "DiceRoller.h"
#include "Monster.h"
#include "Map.h"
#include "Chest.h"
#include "StrategyN.h"



using namespace std;

class HumanStrategyN : public StrategyN {

 public:
  HumanStrategyN();
  ~HumanStrategyN();
  void execute(GameStateN*, Character*);
  bool openChest(Character*, Chest*, Map*);
  Character* monsterPresence(Character*, vector<Character*>, Map*);
  Chest* chestPresence(Character*, vector<Chest*>, Map*);
  bool moveHuman(Coord2D*, Map*, Character*, vector<Character*>);
 private:
  int validate_this_choice(int, int, string);
};

