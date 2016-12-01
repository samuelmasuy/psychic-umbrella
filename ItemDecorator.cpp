/**
 * @file ItemDecorator.h
 * @brief Implementation of Item Decorator subclasses.
 * @author Samuel Masuy
 * @date 2016-11-24
 */
#include "ItemDecorator.h"

using namespace std;

ItemDecorator::ItemDecorator(Character * decoratedCharacter, Item * item) : CharacterDecorator(decoratedCharacter, item)
{
	this->decoratedCharacter = decoratedCharacter;
	this->item = item;
	isEmpty = false;
	isWearing = true;

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
}

int ItemDecorator::getIntelligence() {
	return decoratedCharacter->getIntelligence() + (isEmpty ? 0 : intelligence);
}

int ItemDecorator::getWisdom() {
	return decoratedCharacter->getIntelligence() + (isEmpty ? 0 : wisdom);
}

int ItemDecorator::getStrength() {
	return decoratedCharacter->getIntelligence() + (isEmpty ? 0 : strength);
}

int ItemDecorator::getConstitution() {
	return decoratedCharacter->getConstitution() + (isEmpty ? 0 : constitution);
}

int ItemDecorator::getCharisma()
{
	return decoratedCharacter->getCharisma() + (isEmpty ? 0 : charisma);
}
int ItemDecorator::getDexterity()
{
	return decoratedCharacter->getDexterity() + (isEmpty ? 0 : dexterity);
}

Item * ItemDecorator::unEquip(string s) {
	string item_type = item->getType();
	if (!isEmpty) {
		if (s == item_type) {
			isEmpty = true;
			isWearing = false;
			return item;
		}
	}
	return decoratedCharacter->unEquip(s);
}

bool ItemDecorator::isEquiped(string s) {
	string item_type = item->getType();
	if (isWearing) {
		if (s == item_type) {
			isWearing = true;
			return isWearing;
		}
	}
	return decoratedCharacter->isEquiped(s);
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
