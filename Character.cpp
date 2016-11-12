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
	equippedSize = 0;
	currentHitPoints = 10;
	positionX = 0;
	positionY = 0;
	level = 0;

}

Character::Character()
{
	characterType = "fighter";

	//generate stats for Character
	for (int i = 0; i < TOT_STATS; i++)
		abilityScores[i] = generateStats();
	//initializing backpack to emptyItem
	for (int i = 0; i < MAX_ITEMS_EQUIPPED; i++)
		equipment[i] = emptyItem;

	//and set hit points to 10
	currentHitPoints = 10;
	equippedSize = 0;
	notify(); //notifies character observer
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

//! Implementation of ability modifier method.
//! @return int: value of modified ability score entered
int Character::abilityModifier(int ability)
{

	return abilityScores[ability] / 2 - 5;
}

//! Implementation of hit points of character
//! @param currentHitPoints: sets currentHitPoints according to ability modifier
void Character::hpChange()
{
	if (abilityModifier(3) > 1)
		currentHitPoints = 10 + (level - 1) * (10 / 2 + 1) + (abilityModifier(3) * 20);
	else
		currentHitPoints = 10 + (level - 1) * (10 / 2 + 1);
	notify();
}

//! Implementation of level of character
//! @param level: when level is changed the following stats must also change according to D20 rules.
void Character::setLevel(int lvl)
{
	level = lvl;
	hpChange();
	attackBonus();
	damageBonus();
	notify();
}

//! Implementation of armor modifier
//! @return the modifier for armor according to D20 game rules
int Character::armorModifier()
{
	return 10 + abilityModifier(1);

}
//! Implementation of damage bonus which depends on strength ability
//! @return strength ability
int Character::damageBonus()
{
	return abilityModifier(0); 
}
//! Implementation of attack bonus according to D20 game rules
//! @return attackBonus according d20 game
int Character::attackBonus()
{
		return level + abilityModifier(0) + abilityModifier(1);

}

//! Implementation of get level
//! @return level: level f the character
int Character::getLevel(){
	return level;
}

//! Implementation of level up
//! @param level: increase level of character upon level change
void Character::levelUp(){
	level++;
}

//! Implementation of stats generator
//! @return total: random number generated
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


//! Implementation of save character
//! @param saves character into txt file.
void Character::saveCharacter()
{
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
	ofs << equippedSize << endl;
	for (int i = 0; i < MAX_ITEMS_EQUIPPED; i++)
	{
		type = equipment[i].getType();
		if (type != "")
		{
			ofs << equipment[i].getType() << endl;
			ofs << equipment[i].getInfluences().size() << endl;
			for (int j = 0; j < equipment[i].getInfluences().size(); j++)
			{
				ofs << equipment[i].getInfluences().at(0).getType() << endl;
				ofs << equipment[i].getInfluences().at(0).getBonus() << endl;
			}
		}
	}

	if (backpack.getSize() != 0){
		ofs << backpack.getSize() << endl;
		for (int i = 0; i < backpack.getSize(); i++)
		{
			ofs << backpack.getItems().at(i).getType() << endl;
			ofs << backpack.getItems()[i].getInfluences().size() << endl;
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

//! Implementation of load character
//! @param loads character from txt file.
void Character::loadCharacter()
{

	string loadFile;
	string Validation;
	string type;
	bool chooseFileName = false;
	int backpackSize;
	int bonus;
	int size;
	int influenceSize;
	cout << "Load File: ";
	cin >> loadFile;

	ifstream ifs(loadFile);
	do {
		while (!ifs.good()) {
			cout << "File does not exist, try again: ";
			cin >> loadFile;
			ifs.open(loadFile);
		}
		ifs >> Validation;
		if (Validation == "CharFile")//check if it is an item save file
			chooseFileName = true;
		else {
			ifs.close();
			chooseFileName = false;
			cout << "Incorrect File Loaded, select another File: " << endl;
			cin >> loadFile;
			ifs.open(loadFile);
		}
	} while (chooseFileName == false);


	ifs >> level;
	ifs >> currentHitPoints;
	for (int i = 0; i < 6; i++) {
		ifs >> abilityScores[i];
	}
	ifs >> equippedSize;
	if (equippedSize > 0)
	{
		Enhancement* myEnhacement;
		for (int i = 0; i < equippedSize; i++)			//save equipped items
		{
			ifs >> type;
			equipment[i].setType(type);
			ifs >> influenceSize;

			for (int j = 0; j < influenceSize; j++)
			{
				ifs >> type;
				ifs >> bonus;
				myEnhacement = new Enhancement(type, bonus);
				equipment[i].setInfluences(*myEnhacement);
				delete myEnhacement;
			}

		}
	}
	ifs >> backpackSize;
	if (backpackSize != 0)
	{
		Item* myItem;
		Enhancement  *myEnhacements;


		for (int i = 0; i < backpackSize; i++)		//save inventory/backpack
		{
			ifs >> type;
			myItem = new Item();
			myItem->setType(type);
			ifs >> influenceSize;
			for (int j = 0; j < influenceSize; j++)
			{
				ifs >> type;
				ifs >> bonus;
				myEnhacements = new Enhancement(type, bonus);
				myItem->setInfluences(*myEnhacements);
				backpack.addItem(*myItem);
				delete myItem;
				delete myEnhacements;
				//backpack.getItems()[i].getInfluences()[j].setEnhacement(type, bonus);
			}

		}
	}
	ifs.close();
}

//! Implementation of player info
//! @param print character info on screen
void Character::playerInfo()
{
	cout << "-------------------------------\n";
	cout << "Class Type: " << characterType << endl;
	cout << "Level: " << level << endl;
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


//! Implementation of equip item
//! @return bool: states whether item has been equipped or not
bool Character::equipItem(Item* item)
{
	int backpackSize;

	string type = item->getType();

	if (type == "helmet")
	{
		equipment[Helmet] = *item;
	}
	else if (type == "armor")
	{
		equipment[Armor] = *item;
	}
	else if (type == "weapon")
	{
		equipment[Weapon] = *item;
	}
	else if (type == "shield")
	{
		equipment[Shield] = *item;
	}
	else if (type == "ring")
	{
		equipment[Ring] = *item;
	}
	else if (type == "belt")
	{
		equipment[Belt] = *item;
	}
	else if (type == "boots")
	{
		equipment[Boots] = *item;
	}
	else
		return false;


						
	equippedSize++;
	return true;

}
bool Character::equipFromBackpack(int backpackIndex)
{
	string type;

	type = backpack.getItemTypeAtIndex(backpackIndex);
	if (type == "helmet")
	{
		equipment[Helmet] = backpack.getItemAtIndex(backpackIndex);
	}
	else if (type == "armor")
	{
		equipment[Armor] = backpack.getItemAtIndex(backpackIndex);
	}
	else if (type == "weapon")
	{
		equipment[Weapon] = backpack.getItemAtIndex(backpackIndex);
	}
	else if (type == "shield")
	{
		equipment[Shield] = backpack.getItemAtIndex(backpackIndex);
	}
	else if (type == "ring")
	{
		equipment[Ring] = backpack.getItemAtIndex(backpackIndex);
	}
	else if (type == "belt")
	{
		equipment[Belt] = backpack.getItemAtIndex(backpackIndex);
	}
	else if (type == "boots")
	{
		equipment[Boots] = backpack.getItemAtIndex(backpackIndex);
	}
	else
		return false;
	equippedSize++;


	//takes it out of backpack
	backpack.removeItem(backpackIndex);


	return true;

}

//! Implementation of unequip item
//! @return bool: states whether item has been unequipped or not
bool Character::unequipItem(string type)
{
	

	//remove item from correct slot
	if (type == "helmet")
	{
		backpack.addItem(equipment[Helmet]);
		equipment[Helmet] = emptyItem;
	}
	else if (type == "armor")
	{
		backpack.addItem(equipment[Armor]);
		equipment[Armor] = emptyItem;

	}
	else if (type == "weapon")
	{
		backpack.addItem(equipment[Weapon]);
		equipment[Weapon] = emptyItem;
	}
	else if (type == "shield")
	{
		backpack.addItem(equipment[Shield]);
		equipment[Shield] = emptyItem;
	}
	else if (type == "ring")
	{
		backpack.addItem(equipment[Ring]);
		equipment[Ring] = emptyItem;
	}
	else if (type == "belt")
	{
		backpack.addItem(equipment[Belt]);
		equipment[Belt] = emptyItem;
	}
	else if (type == "boots")
	{
		backpack.addItem(equipment[Boots]);
		equipment[Boots] = emptyItem;
	}
	else
		return false;
	equippedSize--;
	return true;
}

//! Implementation of printBackPackItems
//! @param prints backpack items on screen
void Character::printBackPackItems()
{
	backpack.printBackpack();
}

//! Implementation of addToBackPack
//! @param takes in an item and adds item to backpack
void Character::addToBackpack(Item newItem){
	backpack.addItem(newItem);
}

//! Implementation of printEquippedItems
//! @param prints every item equipped onto screen
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

//! Implementation of mutator method of setPositionX
//! @param sets position X of character
void Character::setPositionX(int x){
	positionX = x;
}

//! Implementation of mutator method of  setPositionY
//! @param sets position Y of character
void Character::setPositionY(int y){
	positionY = y;
}

//! Implementation of accessor method getPositionX
//! @return positionX: gets position X of character
int Character::getPositionX(){
	return positionX;
}

//! Implementation of accessor method getPositionY
//! @return positionY: gets position Y of character
int Character::getPositionY(){
	return positionY;
}


//! Implementation of Fighter Class, inherited from Character
//! Default constructor
Fighter::Fighter() : Character(){

		for (int i = 0; i < TOT_STATS; i++)
			abilityScores[i] = generateStats();
		for (int i = 0; i < MAX_ITEMS_EQUIPPED; i++)
			equipment[i] = emptyItem;

		//and set hit points to 10
		currentHitPoints = 10;
		notify();
}


//! Implementation of Fighter Class, inherited from Character
//! constructor
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

//! Implementation of attackBonus method for Fighter
//! return attackBonus parameter for fighter character
int Fighter::attackBonus(){
	return (level * 2) + abilityModifier(0) + abilityModifier(1);
}
