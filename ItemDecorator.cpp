/**
 * @file ItemDecorator.h
 * @brief Implementation of Item Decorator subclasses.
 * @author Samuel Masuy
 * @date 2016-11-24
 */
#include "ItemDecorator.h"

using namespace std;

ItemDecorator::ItemDecorator(CharacterDecorator * decoratedCharacter, Item * item) : CharacterDecorator(decoratedCharacter)
{
	string type = item->getInfluences().at(0).getType();

	if (type == "intelligence") {
		intelligence = item->getInfluences().at(0).getBonus();
	}
	else if (type == "wisdom") {
		wisdom = item->getInfluences().at(0).getBonus();
	}
	else if (type == "strength") {
		strength = item->getInfluences().at(0).getBonus();
	}
	else if (type == "constitution") {
		constitution = item->getInfluences().at(0).getBonus();
	}
	else if (type == "dexterity") {
		dexterity = item->getInfluences().at(0).getBonus();
	}
	else if (type == "charisma") {
		charisma = item->getInfluences().at(0).getBonus();
	}
	map<string, Character*> equip = decoratedCharacter->getEquippedItems();
	equip[type] = decoratedCharacter;
	decoratedCharacter->setEquippedItems(equip);
}

int ItemDecorator::getIntelligence() {
  return CharacterDecorator::getIntelligence() + intelligence;
}
int ItemDecorator::getWisdom() {
  return CharacterDecorator::getWisdom() + wisdom;
}
int ItemDecorator::getStrength() {
  return CharacterDecorator::getStrength() + strength;
}
int ItemDecorator::getConstitution() {
  return CharacterDecorator::getConstitution() + constitution;
}
int ItemDecorator::getCharisma() {
  return CharacterDecorator::getCharisma() + charisma;
}
int ItemDecorator::getDexterity() {
	return CharacterDecorator::getDexterity() + dexterity;
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
