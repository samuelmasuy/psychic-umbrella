//! @file 
//! @brief Header file for the Character class  
//!
#pragma once
#include <map>
#include <sstream>
#include <cmath>
#include <string>
#include <vector>

#include<string>
#include "Subject.h"
#include "ItemContainer.h"


const int MAX_ITEMS_EQUIPPED = 7;
using namespace std;
using std::map;
using std::vector;
using std::string;
using std::stringstream;

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
	virtual int attackBonus();
	int damageBonus();
	void saveCharacter();
	void loadCharacter();
	virtual void playerInfo();
	bool equipItem(Item);
	bool unequipItem(string);
	void printBackPackItems();
	void addToBackpack(Item);
	void printEquippedItems();
	void levelUp();

	virtual int armorClass();
	int getLevel();
	int getHitPoints();

	void setPositionX(int);
	void setPositionY(int)
	int getPositionX();
	int getPositionY();

private:
	string characterType;
	int abilityScores[6];
	int currentHitPoints;
	Item equipment[MAX_ITEMS_EQUIPPED];
	ItemContainer backpack;
	enum equipmentSlots {Helmet, Armor, Weapon, Shield, Ring, Belt, Boots};
	int level;
	const Item emptyItem; //itemholder for equipementSlots
	int positionX;
	int positionY;
};

class Fighter: public Character{
public:
    const static int FIGHTER_HP=10;

    Fighter();
    Fighter(int, int, int, int, int, int);

    void setArmorClass(); //overrides parent function
    void playerInfo();//overrides parent function
    int attackBonus();
};

