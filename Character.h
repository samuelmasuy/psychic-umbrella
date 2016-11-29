//! @file 
//! @brief Header file for the Character class  
//!
#pragma once
#include<string>
#include "Subject.h"
#include "ItemContainer.h"


using namespace std;


//! Class that implements a character 
class Character: public Subject
{
public:
	//logical game functions
	virtual void setCharacterType(string type) = 0;
	virtual bool validateNewCharacter() = 0;
	virtual void hit(int) = 0;
	virtual int generateStats() = 0;
	virtual void hpChange() = 0;
	virtual int abilityModifier(int) = 0;
	virtual int armorModifier() = 0;
	//virtual int attackBonus();//class to be inherited
	virtual void setAttackBonus() = 0;
	virtual void playerInfo() = 0; //displaying character info
	virtual bool equipItem(Item*) = 0;
	virtual bool equipFromBackpack(int) = 0;
	virtual bool unequipItem(string) = 0;
	virtual void printBackPackItems() = 0;
	virtual void addToBackpack(Item) = 0;
	virtual void printEquippedItems() = 0;
	virtual void levelUp() = 0;

	//saving and loading character
	virtual void saveCharacter() = 0;
	virtual void loadCharacter() = 0;
	virtual void setLevel(int) = 0;
	virtual void setPositionX(int) = 0;
	virtual void setPositionY(int) = 0;
	virtual void setStrenght(int) = 0;
	virtual void setDexterity(int) = 0;
	virtual void setConstitution(int) = 0;
	virtual void setIntelligence(int) = 0;
	virtual void setWisdom(int) = 0;
	virtual void setCharisma(int) = 0;

	//game accessor methods
	virtual int getStrenght() = 0;
	virtual int getDexterity() = 0;
	virtual int getConstitution() = 0;
	virtual int getIntelligence() = 0;
	virtual int getWisdom() = 0;
	virtual int getCharisma() = 0;
	virtual int getHitPoints() = 0;
	virtual int getLevel() = 0;
	virtual int getPositionX() = 0;
	virtual int getPositionY() = 0;

	//character accessor methods
	virtual int getAttacksPerRound() = 0;
	virtual string getCharacterType() = 0;
	virtual int* getAbilityScores() = 0;
	virtual int* getAttackBonus() = 0;
	virtual int getDamageBonus() = 0;
};

