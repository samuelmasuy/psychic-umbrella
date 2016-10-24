//! @file 
//! @brief Header file for the Character class  
//!

#pragma once
#include<string>
using namespace std;

//! Class that implements a character 
class Character
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
private: 
	string characterType;
	int abilityScores[6];
	int currentHitPoints;
	int level;
};

