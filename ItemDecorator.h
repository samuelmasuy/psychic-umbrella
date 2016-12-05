/**
 * @file ItemDecorator.h
 * @brief All the subclasses of CharacterDecorator, and thus subclasses
 * of CharacterAbstract Character Decorator.
 * @author Samuel Masuy
 * @date 2016-11-24
 */
#pragma once

#include <iostream>
#include <string>
#include "Character.h"
#include "CharacterDecorator.h"
#include "ItemException.h"
#include "Item.h"

/**
 * @brief Make the Character wear an Item, it is a subclass of
 * CharacterDecorator.
 */
class ItemDecorator: public CharacterDecorator {
 public:
  /**
   * @brief  When creating a decorated Character, pass a Character to be decorated
   * as a parameter and an item. Note that this can be an already-decorated Character.
   *
   * @param decoratedCharacter the (decorated) Character.
   * @param item the item that the Character should wear.
   */
  ItemDecorator(Character *decoratedCharacter, Item *item);
  /**
  * Overriding methods defined in the abstract superclass.
  * Enables to provide different behavior for decorated Character methods.
  */
  int getIntelligence();
  int getWisdom();
  int getStrength();
  int getConstitution();
  int getCharisma();
  int getDexterity();
  Item* unEquip(string s);
  bool isEquiped(string s);

 private:
  Item *i;
  bool isEmpty;
  bool isWearing;
  int intelligence;
  int wisdom;
  int strength;
  int constitution;
  int charisma;
  int dexterity;
};
