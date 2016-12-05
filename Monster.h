/*
 * Monster.h
 *
 *  Created on: Nov 30, 2016
 *      Author: ahmad
 */
#pragma once
#include "Fighter.h"

namespace std {

class Monster: public Fighter {
 public:
  Monster();
  Monster(int, int, int, int, int);
  virtual ~Monster();
  void setCharacterType(string type);
  void levelUp();
  void setLevel(int);

 private:
  int level;
  int damage;
  string monsterType;

};

} /* namespace std */
