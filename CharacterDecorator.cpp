/**
 * @file CharacterDecorator.cpp
 * @brief Implementation of the the Character Decorator
 * abstract class.
 * @author Samuel Masuy
 * @date 2016-11-24
 */
#include "CharacterDecorator.h"

using namespace std;

//void CharacterDecorator::unequip(string removeType) {
//  if (decoratedCharacter->getEquippedItems()[removeType] != nullptr) {
//      map<string, Character*> str = decoratedCharacter->getEquippedItems();
//      str.erase(removeType);
//      decoratedCharacter->setEquippedItems(str);
//  }
//}
//
//void CharacterDecorator::setEquippedItems(map<string, Character*> newEquipedItems) {
//  equipedItems = newEquipedItems;
//}
//
//map<string, Character*> CharacterDecorator::getEquippedItems() {
//  return equipedItems;
//}
//
void CharacterDecorator::playerInfo() {
	cout << "-------------------------------\n";
	cout << "Class Type: " << decoratedCharacter->getCharacterType() << endl;
	cout << "Level: " << decoratedCharacter->getLevel() << endl;
	cout << "Total HP: " << decoratedCharacter->getHitPoints() << endl;
	cout << "Total armor: " << decoratedCharacter->armorModifier() << endl;
	cout << "Strenght: " << getStrength() << endl;
	cout << "Dexterity: " << getDexterity() << endl;
	cout << "Constituion: " << getConstitution() << endl;
	cout << "Intelect: " << getIntelligence() << endl;
	cout << "Wizdom: " << getWisdom() << endl;
	cout << "Charisma: " << getCharisma() << endl;
	cout << "Damange bonus: " << decoratedCharacter->getDamageBonus() << endl;
	cout << "Attack bonus: ";
	if (decoratedCharacter->getAttacksPerRound() > 1)
	{
		for (int i = 0; i < decoratedCharacter->getAttacksPerRound(); i++)
		{
			cout << *(decoratedCharacter->getAttackBonus() + i) << " ; ";
		}
		cout << endl;
	}
	else
		cout << *(decoratedCharacter->getAttackBonus() + 0) << " ";


	cout << "Attacks per/round: " << decoratedCharacter->getAttacksPerRound() << endl;
	cout << "-------------------------------\n";

}

void CharacterDecorator::printEquippedItems() {
	if (isEquiped(item->getType())) {
		cout << item->getType();
		cout << " {" << item->getInfluences().at(0).getType() << " +";
		cout << item->getInfluences().at(0).getBonus() << "}" << endl;
	}
	decoratedCharacter->printEquippedItems();
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
