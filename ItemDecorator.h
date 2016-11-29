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
#include "Item.h"

class ItemDecorator: public CharacterDecorator {
  public:
    ItemDecorator(Character *decoratedCharacter, Item *item);
    int getIntelligence();
    int getWisdom();
    int getStrength();
    int getConstitution();
    int getCharisma();
	int getDexterity();
private:
	int intelligence;
	int wisdom;
	int strength;
	int constitution;
	int charisma;
	int dexterity;
};
