/**
 * @file ItemDecorator.h
 * @brief All the subclasses of CharacterDecorator, and thus subclasses
 * of CharacterAbstract Character Decorator.
 * @author Samuel Masuy
 * @date 2016-11-24
 */
#pragma once

#include <string>
#include "Character.h"
#include "CharacterDecorator.h"
#include "ItemException.h"

/**
 * @brief Make the Character wear a Helmet, it is a subclass of
 * CharacterDecorator.
 */
class Helmet: public CharacterDecorator {
 public:
  /**
   * @brief  When creating a decorated Character, pass a Character to be decorated
   * as a parameter. Note that this can be an already-decorated Character.
   *
   * @param decoratedCharacter the (decorated) Character.
   */
  Helmet(Character *decoratedCharacter);
  /**
  * Overriding methods defined in the abstract superclass.
  * Enables to provide different behavior for decorated Character methods.
  */
  int getIntelligence();
  int getWisdom();
  int getArmor();
 private:
  int intelligence;
  int wisdom;
  int armor;
};

/**
 * @brief Make the Character wear an Armor, it is a subclass of
 * CharacterDecorator.
 */
class Armor : public CharacterDecorator {
 public:
  Armor(Character *decoratedCharacter);
  int getArmor();
 private:
  int armor;
};

/**
 * @brief Make the Character wear a Shield, it is a subclass of
 * CharacterDecorator.
 */
class Shield : public CharacterDecorator {
 public:
  Shield(Character *decoratedCharacter);
  int getArmor();
 private:
  int armor;
};

/**
 * @brief Make the Character wear a Ring, it is a subclass of
 * CharacterDecorator.
 */
class Ring : public CharacterDecorator {
 public:
  Ring(Character *decoratedCharacter);
  int getArmor();
  int getStrength();
  int getConstitution();
  int getWisdom();
  int getCharisma();
 private:
  int armor;
  int strength;
  int constitution;
  int wisdom;
  int charisma;
};

/**
 * @brief Make the Character wear a Belt, it is a subclass of
 * CharacterDecorator.
 */
class Belt : public CharacterDecorator {
 public:
  Belt(Character *decoratedCharacter);
  int getConstitution();
  int getStrength();
 private:
  int constitution;
  int strength;
};

/**
 * @brief Make the Character wear Boots, it is a subclass of
 * CharacterDecorator.
 */
class Boots : public CharacterDecorator {
 public:
  Boots(Character *decoratedCharacter);
  int getArmor();
  int getDexterity();
 private:
  int dexterity;
  int armor;
};

/**
 * @brief Make the Character wear a Weapon, it is a subclass of
 * CharacterDecorator.
 */
class Weapon : public CharacterDecorator {
 public:
  Weapon(Character *decoratedCharacter);
  int getAttack();
  int getDamage();
 private:
  int attack;
  int damage;
};
