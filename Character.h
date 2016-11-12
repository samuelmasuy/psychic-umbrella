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

	//constructors
	Character();
	Character(int, int, int, int, int, int);

	//logical game functions
	bool validateNewCharacter();
	void hit(int);
	int generateStats();
	void hpChange();
	int abilityModifier(int);
	int armorModifier();
	virtual int attackBonus();//class to be inherited
	int damageBonus();
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
	
protected:
	int currentHitPoints;
	Item equipment[MAX_ITEMS_EQUIPPED];
	const Item emptyItem; //itemholder for equipementSlots
	int level;

private:
	string characterType;
	int abilityScores[6];
	ItemContainer backpack;
	enum equipmentSlots {Helmet, Armor, Weapon, Shield, Ring, Belt, Boots};
	int positionX;
	int positionY;
	int equippedSize;
};

//Fighter class inherited from Character class
class Fighter: public Character{
public:
    const static int FIGHTER_HP=10;

    //Fighter constructors
    Fighter();
    Fighter(int, int, int, int, int, int);

    //fighter attack bonus
    int attackBonus();

private:
	int abilityScores[6];
};
