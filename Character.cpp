//! @file 
//! @brief Implementation file for the Character class  
//!

#include "Character.h"
#include "Observer.h"
#include <stdlib.h> 
#include <random>
#include <fstream>
#include <iostream>
#include "ItemContainer.h"


using namespace std;

const int  TOT_STATS = 6;
const string filename = "characterSaved.dat";

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
	for (int i = 0; i < MAX_ITEMS_EQUIPPED; i++)
		equipment[i] = emptyItem;
	
	//and set hit points to 10
	currentHitPoints = 10;
	notify();
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
	notify();
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
	if (abilityModifier(3) > 1)
		currentHitPoints = 10 + (level - 1) * (10 / 2 + 1) + (abilityModifier(3) * 20);
	else
		currentHitPoints = 10 + (level - 1) * (10 / 2 + 1);
	notify();
}


void Character::setLevel(int lvl)
{
	level = lvl;
	hpChange();
	attackBonus();
	damageBonus();
	notify();
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

void Character::saveCharacter(Character* character)
{
	/*
	ofstream ofs("savedCharacter.ros", ios::binary);
	ofs.write((char *)&character, sizeof(character));
	ofs.close();
	*/
	
	ofstream outfile;
	outfile.open(filename.c_str(), ios::out | ios::app | ios::binary);
	outfile.write((char *)(&character), sizeof(character));
	outfile.close();

}
void Character::loadCharacter(Character* character)
{
	/*ifstream ifs("savedCharacter.ros", ios::binary);
	ifs.read((char *)&character, sizeof(character));
	ifs.close();
	*/
	ifstream infile;
	infile.open(filename.c_str(), ios::binary);

	while (infile.read((char *)&character, sizeof(character)))
	infile.close();
}

void Character::playerInfo()
{
	cout << "-------------------------------\n";
	cout << "Class Type: " << characterType << endl;
	cout << "Total HP: " << currentHitPoints << endl;
	cout << "Total armor: " << armorModifier() << endl;
	cout << "Strenght: " << abilityScores[0] << endl;
	cout << "Dexterity: " << abilityScores[1] << endl;
	cout << "Constituion: " << abilityScores[2] << endl;
	cout << "Intelect: " << abilityScores[3] << endl;
	cout << "Wizdom: " << abilityScores[4] << endl;
	cout << "Charisma: " << abilityScores[5] << endl;
	cout << "Damange bonus: " << damageBonus() << endl;
	cout << "Attack bonus: " << attackBonus() << endl;
	cout << "-------------------------------\n";
}

bool Character::equipItem(Item item)
{
	string type = item.getType();

	if (type == "Helmet")
	{
		equipment[Helmet] = item;
	}
	else if (type == "Armor")
	{
		equipment[Armor] = item;
	}
	else if (type == "Weapon")
	{
		equipment[Weapon] = item;
	}
	else if (type == "Shield")
	{
		equipment[Shield] = item;
	}
	else if (type == "Ring")
	{
		equipment[Ring] = item;
	}
	else if (type == "Belt")
	{
		equipment[Belt] = item;
	}
	else if (type == "Boots")
	{
		equipment[Boots] = item;
	}
	else
		return false;

	backpack.removeItem(type);
	return true;
}

bool Character::unequipItem(string itemToRemove)
{
	string type = itemToRemove;

	//remove item from correct slot
	if (type == "Helmet")
	{
		backpack.addItem(equipment[Helmet]);
		equipment[Helmet] = emptyItem;
	}
	else if (type == "Armor")
	{
		backpack.addItem(equipment[Armor]);
		equipment[Armor] = emptyItem;
	}
	else if (type == "Weapon")
	{
		backpack.addItem(equipment[Weapon]);
		equipment[Weapon] = emptyItem;
	}
	else if (type == "Shield")
	{
		backpack.addItem(equipment[Shield]);
		equipment[Shield] = emptyItem;
	}
	else if (type == "Ring")
	{
		backpack.addItem(equipment[Ring]);
		equipment[Ring] = emptyItem;
	}
	else if (type == "Belt")
	{
		backpack.addItem(equipment[Belt]);
		equipment[Belt] = emptyItem;
	}
	else if (type == "Boots")
	{
		backpack.addItem(equipment[Boots]);
		equipment[Boots] = emptyItem;
	}
	else
		return false;

	return true;
}