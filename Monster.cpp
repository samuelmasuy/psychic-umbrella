/*
 * Monster.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: ahmad
 */

#include "Monster.h"

Monster::Monster() {
  positionX = 0;
  positionY = 0;
  monsterType = "monster";
  damage = 0;
  level = 1;
}

Monster::Monster(int hp, int posX, int posY, int lvl, int dam) {
  positionX = posX;
  positionY = posY;
  monsterType = "monster";
  level = lvl;
  damage = dam;
}

Monster::~Monster() {
}

void Monster::setCharacterType(string type) {
  monsterType = type;
}

void Monster::levelUp() {
  level++;
}

void Monster::setLevel(int lvl) {
  level = lvl;
}
