//! @file 
//! @brief Implementation file for the Character class  
//!

#include "Character.h"
#include <stdlib.h> 
#include <random>

const int  TOT_STATS = 6;
//! Constructor: passes values to each ability score and set hit points to 10
Character::Character(int str, int dex, int con, int intel, int wis, int cha)
{
	abilityScores[0] = str; 
	abilityScores[1] = dex;
	abilityScores[2] = con;
	abilityScores[3] = intel;
	abilityScores[4] = wis;
	abilityScores[5] = cha;

	//and set hit points to 10
	currentHitPoints = 10;
}

Character::Character()
{
	characterType = "fighter";
	
	for (int i = 0; i < TOT_STATS; i++)
		abilityScores[i] = generateStats();
	
	//and set hit points to 10
	currentHitPoints = 10;
	
}

//! Implementation of the verification of a newly created Character
//! @return bool value, true of the character is valid (stats should be in the 3-18 range for a new character), false if invalid. 
bool Character::validateNewCharacter()
{
	for (int i = 0; i <= 5; i++)
	if (abilityScores[i]<3 || abilityScores[i]>18)
		return false;
	return true;
}

//! Implementation of fill cell, set any cell to anything it might eventually contain
//! @param damage: damage sustained by the character
void Character::hit(int damage)
{
	currentHitPoints = currentHitPoints - damage; 
}

//! Implementation of a getter method for currentHitPoints
//! @return int: value of currentHitPoints
int Character::getHitPoints()
{
	return currentHitPoints; 
}


int Character::abilityModifier(int ability)
{

	return abilityScores[ability] / 2 - 5;
}

void Character::hpChange()
{
	 currentHitPoints = 10 + (level - 1) * (10 / 2 + 1) + (abilityModifier(3) * 20);
}


void Character::setLevel(int lvl)
{
	level = lvl;
}

int Character::armorModifier()
{
	return 10 + abilityModifier(1);
}

int Character::damageBonus()
{
	return abilityModifier(0); 
}

int Character::attackBonus()
{
	if (characterType != "fighter")
		return level + abilityModifier(0) + abilityModifier(1);
	else
		return (level * 2) + abilityModifier(0) + abilityModifier(1);
}

int Character::generateStats()
{
	int score = 0;
	int diceTurns[4] = {};
	//score = rand() % 6 + 1;
	int lowest = 6;
	int total = 0;
	// Random seed
	random_device rd;
	// Initialize Mersenne Twister pseudo-random number generator
	mt19937 gen(rd());
	// Generate pseudo-random numbers
	// uniformly distributed in range (1, 6)
	uniform_int_distribution<> rand(1, 6);

	for (int i = 0; i < 4; i++)
	{
		score = rand(gen);;
		diceTurns[i] = score;

		if (diceTurns[i] < lowest)
		{
			lowest = diceTurns[i];
		}
		total += diceTurns[i];
	}
	total -= lowest;

	return total;
}