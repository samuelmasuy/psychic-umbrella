/**
 * @file CharacterDecorator.h
 * @brief Abstract Character Decorator
 * @author Samuel Masuy
 * @date 2016-11-24
 */
#pragma once

#include <string>
#include "Character.h"
#include "map.h"

/**
 * @brief Abstract decorator class - note that it extends the Character abstract class.
 */
class CharacterDecorator : public Character {
 public:
  /**
   * @brief Wraps a Character object inside an object of one of
   * CharacterDecorator's subclasses
   *
   * @param decoratedCharacter a Character.
   */
  CharacterDecorator(Character *decoratedCharacter) {
    this->decoratedCharacter = decoratedCharacter;
  }
  virtual ~CharacterDecorator() {
  }
  /**
  * Provides the wrapper with the Character interface and delegates
  * its methods to the wrapped Character object.
  */
  // int getStrength() {
  //   return decoratedCharacter->getStrength();
  // }
  void unequip(string);
  void setEquippedItems(map<string, Character*>);
  map<string, Character*> getEquippedItems();
  int getBonus(string);
  // Character* remove(string);
  // bool isTypeExist(string);

 protected:
  Character *decoratedCharacter;
  map<string, Character*> equipedItems;
  // string type;
};
