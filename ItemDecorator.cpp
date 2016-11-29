/**
 * @file ItemDecorator.h
 * @brief Implementation of Item Decorator subclasses.
 * @author Samuel Masuy
 * @date 2016-11-24
 */
#include "ItemDecorator.h"

using namespace std;

ItemDecorator::ItemDecorator(Character *decoratedCharacter, Item* item) : CharacterDecorator(decoratedCharacter) {
    type = item->getInfluences().at(0).getType();

    if (type.compare("intelligence" == 0)) {
      intelligence = item->getInfluences().at(0).getBonus();
    } else if (type.compare("wisdom" == 0)) {
      wisdom = item->getInfluences().at(0).getBonus();
    } else if (type.compare("armor" == 0)) {
      armor = item->getInfluences().at(0).getBonus();
    } else if (type.compare("strength" == 0)) {
      strength = item->getInfluences().at(0).getBonus();
    } else if (type.compare("constitution" == 0)) {
      constitution = item->getInfluences().at(0).getBonus();
    } else if (type.compare("wisdom" == 0)) {
      wisdom = item->getInfluences().at(0).getBonus();
    } else if (type.compare("charisma" == 0)) {
      charisma = item->getInfluences().at(0).getBonus();
    }
    map<string, *Character> equip = decoratedCharacter->getEquippedItems();
    equip[type] = decoratedCharacter;
    character->setEquippedItems(equip);
}

int ItemDecorator::getIntelligence() {
  return CharacterDecorator::getIntelligence() + intelligence;
}
int ItemDecorator::getWisdom() {
  return CharacterDecorator::getWisdom() + wisdom;
}
int ItemDecorator::getArmor() {
  return CharacterDecorator::getArmor() + armor;
}
int ItemDecorator::getStrength() {
  return CharacterDecorator::getStrength() + strength;
}
int ItemDecorator::getConstitution() {
  return CharacterDecorator::getConstitution() + constitution;
}
int ItemDecorator::getWisdom() {
  return CharacterDecorator::getWisdom() + wisdom;
}
int ItemDecorator::getCharisma() {
  return CharacterDecorator::getCharisma() + charisma;
}

// nimble = new Helmet(nimble)
// Helmet::Helmet(Character *decoratedCharacter) : CharacterDecorator(decoratedCharacter) {
  // director
  // dierectobuild helmet
  // item = get helmet

// int Helmet::getItem(string type) {
//   return map[type]; -> item
// }

// item = nimble->getItem(type)
// nimble->remove(type)
// nimble->backpack->addItem(item)
