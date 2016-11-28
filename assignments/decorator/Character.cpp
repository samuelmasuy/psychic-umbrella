/**
 * @file Character.cpp
 * @brief Implementation of Fighter super abstract class.
 * @author Samuel Masuy
 * @date 2016-11-24
 */
#include "Character.h"

using namespace std;

int Fighter::getStrength() {
  return 0;
}
int Fighter::getArmor() {
  return 0;
}
int Fighter::getConstitution() {
  return 0;
}
int Fighter::getWisdom() {
  return 0;
}
int Fighter::getCharisma() {
  return 0;
}
int Fighter::getDexterity() {
  return 0;
}
int Fighter::getAttack() {
  return 0;
}
int Fighter::getDamage() {
  return 0;
}
int Fighter::getIntelligence() {
  return 0;
}
Character*  Fighter::remove(string removeType) {
  return this;
}
bool Fighter::isTypeExist(string removeType) {
  return false;
}
