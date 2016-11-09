//! @file 
//! @brief Header file for the Character class  
//!

#pragma once
#include<string>
#include "Subject.h"
#include "ItemContainer.h"
const int MAX_ITEMS_EQUIPPED = 7;
using namespace std;

//! Class that implements a character 
class Character : public Subject
{
public:
	Character();
	Character(int, int, int, int, int, int);
	bool validateNewCharacter();
	void hit(int);
	int generateStats();
	int getHitPoints();
	void hpChange();
	int abilityModifier(int);
	void setLevel(int);
	int armorModifier();
	int attackBonus();
	int damageBonus();
	void saveCharacter();
	void loadCharacter();
	void playerInfo();
	bool equipItem(Item);
	bool unequipItem(string);
	void printBackPackItems();
	void addToBackpack(Item);
	void printEquippedItems();
private: 
	string characterType;
	int abilityScores[6];
	int currentHitPoints;
	Item equipment[MAX_ITEMS_EQUIPPED];
	ItemContainer backpack;
	enum equipmentSlots {Helmet, Armor, Weapon, Shield, Ring, Belt, Boots};
	int level;
	const Item emptyItem; //itemholder for equipementSlots
};

