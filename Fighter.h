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
class Fighter : public Subject, Character
{
public:

	//constructors
	Fighter();
	Fighter(int, int, int, int, int, int);

	//logical game functions
	void setCharacterType(string type);
	bool validateNewCharacter();
	void hit(int);
	int generateStats();
	void hpChange();
	int abilityModifier(int);
	int armorModifier();
	//virtual int attackBonus();//class to be inherited
	void setAttackBonus();
	void playerInfo(); //displaying character info
	bool equipItem(Item*);
	bool equipFromBackpack(int);
	bool unequipItem(string);
	void printBackPackItems();
	void addToBackpack(Item);
	void printEquippedItems();
	void levelUp();

	//saving and loading character
	void saveCharacter();
	void loadCharacter();
	void setLevel(int);
	void setPositionX(int);
	void setPositionY(int);

	//game accessor methods
	int getHitPoints();
	int getLevel();
	int getPositionX();
	int getPositionY();

	//character accessor methods
	int getAttacksPerRound();
	string getCharacterType();
	int* getAbilityScores();
	int* getAttackBonus();
	int getDamageBonus();
protected:
	int currentHitPoints;
	Item equipment[MAX_ITEMS_EQUIPPED];
	const Item emptyItem; //itemholder for equipementSlots
	int level;
	int abilityScores[6];
	//int atkBonus;
	int attacksPerRound;
	int experience, gold;
	int* bonusAttack = new int (1);

private:
	string characterType;
	ItemContainer backpack;
	enum equipmentSlots {Helmet, Armor, Weapon, Shield, Ring, Belt, Boots};
	int positionX;
	int positionY;
	int equippedSize;
};
