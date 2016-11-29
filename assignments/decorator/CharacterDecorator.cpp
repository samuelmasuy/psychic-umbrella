/**
 * @file CharacterDecorator.cpp
 * @brief Implementation of the the Character Decorator
 * abstract class.
 * @author Samuel Masuy
 * @date 2016-11-24
 */
#include "CharacterDecorator.h"

using namespace std;

Character* CharacterDecorator::remove(string removeType) {
  if(removeType.compare(type) == 0) {
    Character* childRef = decoratedCharacter;
    decoratedCharacter = NULL; // prevent the destructor from recursing
    delete this;
    return childRef;
  }
  return decoratedCharacter->remove(removeType);
}


class CharacterDecorator : public Character {
   public:
        CharacterDecorator(Character*);
        ~CharacterDecorator();
        void remove(string);
        map<string, Character*> getEquippedItems();
        void setEquippedItems(map<string, Character*>);
        string getEnchantment();
    protected:
        Character* character;
};
void CharacterDecorator::remove(string type)
{
        if (character->getEquippedItems()[type] != nullptr)
        {
                map<string, Character*> str = character->getEquippedItems();
                str.erase(type);
                character->setEquippedItems(str);
        }
}

bool CharacterDecorator::isTypeExist(string compareType) {
  if(compareType.compare(type) == 0) {
    return true;
  }
  return decoratedCharacter->isTypeExist(compareType);
}
