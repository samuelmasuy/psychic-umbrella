//! @file 
//! @brief Header file for the Character class  
//!
#pragma once
#include <string>
#include <map>
#include "Subject.h"
#include "ItemContainer.h"
#include "Character.h"


const int MAX_ITEMS_EQUIPPED = 7;
using namespace std;


//! Class that implements a character 
class Fighter : public Character
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
	void setStrength(int);
	void setDexterity(int);
	void setConstitution(int);
	void setIntelligence(int);
	void setWisdom(int);
	void setCharisma(int);

	//game accessor methods
	int getHitPoints();
	int getLevel();
	int getPositionX();
	int getPositionY();

	//character accessor methods
	int getStrength();
	int getDexterity();
	int getConstitution();
	int getIntelligence();
	int getWisdom();
	int getCharisma();
	int getAttacksPerRound();
	string getCharacterType();
	int* getAbilityScores();
	int* getAttackBonus();
	int getDamageBonus();

  //decorator
  void unequip(string);
  void setEquippedItems(map<string, Character*>);
  map<string, Character*> getEquippedItems();
protected:
	int currentHitPoints;
	Item equipment[MAX_ITEMS_EQUIPPED];
	const Item emptyItem; //itemholder for equipementSlots
	int level = 1;
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
