/**
 * @file CharacterDecorator.cpp
 * @brief Implementation of the the Character Decorator
 * abstract class.
 * @author Samuel Masuy
 * @date 2016-11-24
 */
#include "CharacterDecorator.h"

using namespace std;

void CharacterDecorator::unequip(string removeType) {
  if (decoratedCharacter->getEquippedItems()[removeType] != nullptr) {
      map<string, Character*> str = decoratedCharacter->getEquippedItems();
      str.erase(removeType);
      decoratedCharacter->setEquippedItems(str);
  }
}

void CharacterDecorator::setEquippedItems(map<string, Character*> newEquipedItems) {
  equipedItems = newEquipedItems;
}

map<string, Character*> CharacterDecorator::getEquippedItems() {
  return equipedItems;
}

void CharacterDecorator::printEquippedItems() {
	for (map<string, Character*>::iterator it = equipedItems.begin(); it != equipedItems.end(); ++it) {
		cout << it->first << "\n";
	}
}

// Character* CharacterDecorator::remove(string removeType) {
//   if(removeType.compare(type) == 0) {
//     Character* childRef = decoratedCharacter;
//     decoratedCharacter = NULL; // prevent the destructor from recursing
//     delete this;
//     return childRef;
//   }
//   return decoratedCharacter->remove(removeType);
// }

// bool CharacterDecorator::isTypeExist(string compareType) {
//   if(compareType.compare(type) == 0) {
//     return true;
//   }
//   return decoratedCharacter->isTypeExist(compareType);
// }
