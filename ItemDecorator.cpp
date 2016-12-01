/**
 * @file ItemDecorator.h
 * @brief Implementation of Item Decorator subclasses.
 * @author Samuel Masuy
 * @date 2016-11-24
 */
#include "ItemDecorator.h"

using namespace std;

ItemDecorator::ItemDecorator(Character * decoratedCharacter, Item * item) : CharacterDecorator(decoratedCharacter)
{
	string item_type = item->getType();
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
	equip[item_type] = decoratedCharacter;
	setEquippedItems(equip);
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
void ItemDecorator::playerInfo()
{
	cout << "-------------------------------\n";
	cout << "Class Type: " << CharacterDecorator::getCharacterType() << endl;
	cout << "Level: " << CharacterDecorator::getLevel() << endl;
	cout << "Total HP: " << CharacterDecorator::getHitPoints() << endl;
	cout << "Total armor: " << CharacterDecorator::armorModifier() << endl;
	cout << "Strenght: " << getStrength() << endl;
	cout << "Dexterity: " << getDexterity() << endl;
	cout << "Constituion: " << getConstitution() << endl;
	cout << "Intelect: " << getIntelligence() << endl;
	cout << "Wizdom: " << getWisdom() << endl;
	cout << "Charisma: " << getCharisma() << endl;
	cout << "Damange bonus: " << CharacterDecorator::getDamageBonus() << endl;
	cout << "Attack bonus: ";
	if (CharacterDecorator::getAttacksPerRound() > 1)
	{
		for (int i = 0; i < CharacterDecorator::getAttacksPerRound(); i++)
		{
			cout << *(CharacterDecorator::getAttackBonus() + i) << " ; ";
		}
		cout << endl;
	}
	else
		cout << *(CharacterDecorator::getAttackBonus() + 0) << " ";


	cout << "Attacks per/round: " << CharacterDecorator::getAttacksPerRound() << endl;
	cout << "-------------------------------\n";
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
