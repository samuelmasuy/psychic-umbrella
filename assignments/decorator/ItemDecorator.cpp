/**
 * @file ItemDecorator.h
 * @brief Implementation of Item Decorator subclasses.
 * @author Samuel Masuy
 * @date 2016-11-24
 */
#include "ItemDecorator.h"

using namespace std;

Helmet::Helmet(Character *decoratedCharacter) : CharacterDecorator(decoratedCharacter) {
  type = "helmet";
  if (decoratedCharacter->isTypeExist(type)) {
    throw ItemAlreadyWornException();
  } else {
    intelligence = 2;
    wisdom = 2;
    armor = 2;
  }
}

int Helmet::getIntelligence() {
  return CharacterDecorator::getIntelligence() + intelligence;
}
int Helmet::getWisdom() {
  return CharacterDecorator::getWisdom() + wisdom;
}
int Helmet::getArmor() {
  return CharacterDecorator::getArmor() + armor;
}

Armor::Armor(Character *decoratedCharacter) : CharacterDecorator(decoratedCharacter) {
  type = "armor";
  if (decoratedCharacter->isTypeExist(type)) {
    throw ItemAlreadyWornException();
  } else {
    armor = 1;
  }
}

int Armor::getArmor() {
  return CharacterDecorator::getArmor() + armor;
}

Shield::Shield(Character *decoratedCharacter) : CharacterDecorator(decoratedCharacter) {
  type = "shield";
  if (decoratedCharacter->isTypeExist(type)) {
    throw ItemAlreadyWornException();
  } else {
    armor = 4;
  }
}

int Shield::getArmor() {
  return CharacterDecorator::getArmor() + armor;
}

Ring::Ring(Character *decoratedCharacter) : CharacterDecorator(decoratedCharacter) {
  type = "ring";
  if (decoratedCharacter->isTypeExist(type)) {
    throw ItemAlreadyWornException();
  } else {
    armor = 3;
    strength = 3;
    constitution = 3;
    wisdom = 3;
    charisma = 3;
  }
}

int Ring::getArmor() {
  return CharacterDecorator::getArmor() + armor;
}
int Ring::getStrength() {
  return CharacterDecorator::getStrength() + strength;
}
int Ring::getConstitution() {
  return CharacterDecorator::getConstitution() + constitution;
}
int Ring::getWisdom() {
  return CharacterDecorator::getWisdom() + wisdom;
}
int Ring::getCharisma() {
  return CharacterDecorator::getCharisma() + charisma;
}

Belt::Belt(Character *decoratedCharacter) : CharacterDecorator(decoratedCharacter) {
  type = "belt";
  if (decoratedCharacter->isTypeExist(type)) {
    throw ItemAlreadyWornException();
  } else {
    constitution = 1;
    strength = 1;
  }
}

int Belt::getConstitution() {
  return CharacterDecorator::getConstitution() + constitution;
}
int Belt::getStrength() {
  return CharacterDecorator::getStrength() + strength;
}

Boots::Boots(Character *decoratedCharacter) : CharacterDecorator(decoratedCharacter) {
  type = "boots";
  if (decoratedCharacter->isTypeExist(type)) {
    throw ItemAlreadyWornException();
  } else {
    dexterity = 5;
    armor = 5;
  }
}

int Boots::getDexterity() {
  return CharacterDecorator::getDexterity() + dexterity;
}
int Boots::getArmor() {
  return CharacterDecorator::getArmor() + armor;
}

Weapon::Weapon(Character *decoratedCharacter) : CharacterDecorator(decoratedCharacter) {
  type = "weapon";
  if (decoratedCharacter->isTypeExist(type)) {
    throw ItemAlreadyWornException();
  } else {
    attack = 4;
    damage = 4;
  }
}

int Weapon::getAttack() {
  return CharacterDecorator::getAttack() + attack;
}
int Weapon::getDamage() {
  return CharacterDecorator::getDamage() + damage;
}
