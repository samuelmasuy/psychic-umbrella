#include "Strategy.h"


Strategy::Strategy() {
}


Strategy::~Strategy() {
}

vector<int> Strategy::checkAdjacentCell(int inputX, int inputY, Map* inputMap) {
  vector<int> outputLocation;
  if (inputMap->ValidPos(inputX + 1, inputY + 1) && inputMap->GetCell(inputX + 1, inputY + 1) == CHAR_CHEST) {
    outputLocation.push_back(inputX);
    outputLocation.push_back(inputY);
  }
  return outputLocation;
}


void Strategy::combat(Character* monster) {
  /*int totalDmg;


  for (int i = 0; i < attacksPerRound; i++)
  {
  //roll dice for dmg
  int roll = diceRoll(20);

  switch (attacksPerRound)
  {
  case 1:
  {
  totalDmg = bonusAttack[0] + getDamageBonus() + roll;
  cout << "First blow: " << totalDmg << "dmg" << endl;
  monster->MonsterHp -= total;
  }break;

  case 2:
  {
  totalDmg = bonusAttack[1] + getDamageBonus() + roll;
  cout << "Second blow: " << totalDmg << "dmg" << endl;
  monster->MonsterHp -= total;
  }break;

  case 3:
  {
  totalDmg = bonusAttack[2] + getDamageBonus() + roll;
  cout << "Third blow: " << totalDmg << "dmg" << endl;
  monster->MonsterHp -= total;
  }break;

  case 4:
  {
  totalDmg = bonusAttack[3] + getDamageBonus() + roll;
  cout << "Forth blow: " << totalDmg << "dmg" << endl;
  monster->MonsterHp -= total;
  }break;

  }
  }
  */
}
