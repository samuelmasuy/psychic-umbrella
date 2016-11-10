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
	positionX = 0;
	positionY = 0;
	level = 0;

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
		return level + abilityModifier(0) + abilityModifier(1);

}

void Character::levelUp(){
	level++;
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

void Character::saveCharacter()
{

 /*	ofstream ofs("savedCharacter.ros", ios::binary);
	ofs.write((char *)&character, sizeof(character));
	ofs.close();
*/
	/*
	ofstream outfile;
	outfile.open(filename.c_str(), ios::out | ios::app | ios::binary);
	outfile.write((char *)(&character), sizeof(character));
	outfile.close();
	*/
	string type = "";
	string saveFile;
	cout << "Enter name of file being saved: ";
	cin >> saveFile;


	ofstream ofs(saveFile);
	ofs << "CharFile" << endl;	//define type of save file
	ofs << level << endl;
	ofs << currentHitPoints << endl;
	for (int i = 0; i < 6; i++)
		ofs << abilityScores[i] << endl;

	for (int i = 0; i < MAX_ITEMS_EQUIPPED; i++)
	{
		type = equipment[i].getType();
		if (type != "")
		{
			ofs << equipment[i].getType() << endl;
			for (int j = 0; j < equipment[i].getInfluences().size(); j++)
			{
				ofs << equipment[i].getInfluences().at(0).getType() << endl;
				ofs << equipment[i].getInfluences().at(0).getBonus() << endl;
			}
		}
	}

	if (backpack.getSize() != 0){
		ofs << backpack.getSize();
		for (int i = 0; i < backpack.getSize(); i++)
		{
			ofs << backpack.getItems().at(i).getType() << endl;
			for (int j = 0; j < backpack.getItems()[i].getInfluences().size(); j++)
			{
				ofs << backpack.getItems()[i].getInfluences().at(0).getType() << endl;
				ofs << backpack.getItems()[i].getInfluences().at(0).getBonus() << endl;
			}
		}
	}
	else
		ofs << 0;
	ofs.close();



}
void Character::loadCharacter()
{

	/*
	ifstream infile;
	infile.open(filename.c_str(), ios::binary);

	while (infile.read((char *)&character, sizeof(character)))
	infile.close();
	*/

	string loadFile;
	string Validation;
	string type;
	bool chooseFileName = false;
	int backpackSize;
	int bonus;
	cout << "Load File: ";
	cin >> loadFile;

	ifstream ifs(loadFile);
	do{
		while (!ifs.good()){
			cout << "File does not exist, try again: ";
			cin >> loadFile;
			ifs.open(loadFile);
		}
		ifs >> Validation;
		if (Validation == "CharFile")//check if it is an item save file
			chooseFileName = true;
		else{
			ifs.close();
			chooseFileName = false;
			cout << "Incorrect File Loaded, select another File: " << endl;
			cin >> loadFile;
			ifs.open(loadFile);
		}
	} while (chooseFileName == false);


	ifs >> level;
	ifs >> currentHitPoints;
		for (int i = 0; i < 6; i++){
			ifs >> abilityScores[i];
		}
		for (int i = 0; i < MAX_ITEMS_EQUIPPED; i++)			//save equipped items
		{
			ifs >> equipment[i].getType();
			for (int j = 0; j < equipment[i].getInfluences().size(); j++)
			{
				ifs >> type;
				ifs >> bonus;
				equipment[i].getInfluences()[j].setEnhacement(type, bonus);


			}
		}
		ifs >> backpackSize;
		if (backpackSize != 0)
		{

			for (int i = 0; i < backpack.getSize(); i++)		//save inventory/backpack
			{
				ifs >> backpack.getItems().at(i).getType();
				for (int j = 0; j < backpack.getItems()[i].getInfluences().size(); j++)
				{
					ifs >> type;
					ifs >> bonus;
					backpack.getItems()[i].getInfluences()[j].setEnhacement(type, bonus);
				}

			}
		}
		ifs.close();
}

void Character::playerInfo()
{
	cout << "-------------------------------\n";
	cout << "Class Type: " << characterType << endl;
	cout << "Level" << getLevel()<<endl;
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

	//if(backpack.getSize() > 0)
		backpack.removeItem(type);
						//takes it out of backpack
	return true;

}

bool Character::unequipItem(string item)
{
	string type = item;

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

void Character::printBackPackItems()
{
	backpack.printBackpack();
}

void Character::addToBackpack(Item newItem){
	backpack.addItem(newItem);
}

void Character::printEquippedItems()
{
	string type;
	cout << "---EQUIPPED ITEMS---\n";
	for (int i= 0; i < MAX_ITEMS_EQUIPPED; i++)
	{
		type = equipment[i].getType();
		if ( type != "")
			cout << equipment[i].getType() << " {" << equipment[i].getInfluences().at(0).getType() << " +" << equipment[i].getInfluences().at(0).getBonus() << "}" << endl;

	}
}

void Character::setPositionX(int x){
	positionX = x;
}

void Character::setPositionY(int y){
	positionY = y;
}

int Character::getPositionX(){
	return positionX;
}

int Character::getPositionY(){
	return positionY;
}


Fighter::Fighter() : Character(){

		for (int i = 0; i < TOT_STATS; i++)
			abilityScores[i] = generateStats();
		for (int i = 0; i < MAX_ITEMS_EQUIPPED; i++)
			equipment[i] = emptyItem;

		//and set hit points to 10
		currentHitPoints = 10;
		notify();
}
Fighter::Fighter(int str, int dex, int con, int intel, int wis, int cha)
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

int Fighter::attackBonus(){
	return (level * 2) + abilityModifier(0) + abilityModifier(1);
}
