//! @file
//! @brief Implementation file for the Fighter class
//!

#include "Fighter.h"
#include "Observer.h"
#include <stdlib.h>
#include <random>
#include <fstream>
#include <iostream>

using namespace std;

const int  TOT_STATS = 6;
const string filename = "characterSaved.dat";

//! Constructor: passes values to each ability score and set hit points to 10
Fighter::Fighter(int str, int dex, int con, int intel, int wis, int cha) {
  abilityScores[0] = str;
  abilityScores[1] = dex;
  abilityScores[2] = con;
  abilityScores[3] = intel;
  abilityScores[4] = wis;
  abilityScores[5] = cha;

  //and set hit points to 10
  currentHitPoints = 10 + abilityModifier(2);
  positionX = 0;
  positionY = 0;
  level = 1;
  armor = 0;
  attacksPerRound = 1;
  gold = 0;
  experience = 0;
  bonusAttack[0] = 0;
}

int Fighter::getAbilityScore(int index) {
  return abilityScores[index];
}

void Fighter::setAbilityScores(int i, int ability) {
  abilityScores[i] = ability;
}


void Fighter::setStrength(int str) {
  abilityScores[0] = str;
}
void Fighter::setDexterity(int dex) {
  abilityScores[1] = dex;
}
void Fighter::setConstitution(int con) {
  abilityScores[2] = con;
}
void Fighter::setIntelligence(int intel) {
  abilityScores[3] = intel;
}
void Fighter::setWisdom(int wis) {
  abilityScores[4] = wis;
}
void Fighter::setCharisma(int cha) {
  abilityScores[5] = cha;
}

int Fighter::getHitPoints() {
  return currentHitPoints;
}
int Fighter::getStrength() {
  return abilityScores[0];
}
int Fighter::getDexterity() {
  return abilityScores[1];
}
int Fighter::getConstitution() {
  return abilityScores[2];
}
int Fighter::getIntelligence() {
  return abilityScores[3];
}
int Fighter::getWisdom() {
  return abilityScores[4];
}
int Fighter::getCharisma() {
  return abilityScores[5];
}
//
//StrategyN* Fighter::getStrategy() {
//  return characterStrategy;
//}

Fighter::Fighter() {
  characterType = "fighter";

  //generate stats for Fighter
  for (int i = 0; i < TOT_STATS; i++)
    abilityScores[i] = generateStats();

  //and set hit points to 10
  currentHitPoints = 10 + abilityModifier(2);
  level = 1;
  attacksPerRound = 1;

  notify(); //notifies Fighter observer
}

//! Implementation of the verification of a newly created Fighter
//! @return bool value, true of the Fighter is valid (stats should be in the 3-18 range for a new Fighter), false if invalid.
bool Fighter::validateNewCharacter() {
  for (int i = 0; i <= 5; i++)
    if (abilityScores[i]<3 || abilityScores[i]>18)
      return false;
  return true;
}

void Fighter::setCharacterType(string type) {

  characterType = type;
}

string Fighter::getCharacterType() {
  return characterType;
}

int* Fighter::getAbilityScores() {

  return abilityScores;
}

//! Implementation of fill cell, set any cell to anything it might eventually contain
//! @param damage: damage sustained by the Fighter
void Fighter::hit(int damage) {
  currentHitPoints = currentHitPoints - damage;
  notify();
}

void Fighter::setHitPoints(int hp) {
  currentHitPoints = hp;
}

//! Implementation of ability modifier method.
//! @return int: value of modified ability score entered
int Fighter::abilityModifier(int ability) {

  return abilityScores[ability] / 2 - 5;
}

//! Implementation of hit points of Fighter
//! @param currentHitPoints: sets currentHitPoints according to ability modifier
void Fighter::hpChange() {
  if (abilityModifier(2) > 1)
    currentHitPoints = 10 + (level - 1) * (10 / 2 + 1) + (abilityModifier(2) * 20);
  else
    currentHitPoints = 10 + (level - 1) * (10 / 2 + 1);
  notify();
}

//! Implementation of level of Fighter
//! @param level: when level is changed the following stats must also change according to D20 rules.
void Fighter::setLevel(int lvl) {
  level = lvl;
  hpChange();
  if (level < 5) {
    attacksPerRound = 1;
  } else if (level > 5 && level < 11) {
    attacksPerRound = 2;
  } else if (level > 10 && level < 16) {
    attacksPerRound = 3;
  } else if (level > 15 && level < 21) {
    attacksPerRound = 4;
  }

  setAttackBonus();
  getDamageBonus();
  notify();
}

void Fighter::setArmor() {
  armor = 10 + abilityModifier(1);
}

//! Implementation of armor modifier
//! @return the modifier for armor according to D20 game rules
int Fighter::armorModifier() {
  //return 10 + abilityModifier(1);
  return armor;

}
//! Implementation of damage bonus which depends on strength ability
//! @return strength ability
int Fighter::getDamageBonus() {
  return abilityModifier(0);
}
//! Implementation of attack bonus according to D20 game rules
//! @return attackBonus according d20 game
void Fighter::setAttackBonus() {

  int bonusPerRound = level;
  if (level % 5 == 1) {

    attacksPerRound++;
    bonusAttack = new int(attacksPerRound);
  }


  for (int i = 0; i < attacksPerRound; i++) {
    if (bonusPerRound > 0) {
      bonusAttack[i] = bonusPerRound;
      bonusPerRound -= 5;
    }

  }
}

int* Fighter::getAttackBonus() {
  return bonusAttack;
}

int Fighter::getAttacksPerRound() {
  return ceil(level / 5.0);
}


//! Implementation of get level
//! @return level: level f the Fighter
int Fighter::getLevel() {
  return level;
}

//! Implementation of level up
//! @param level: increase level of Fighter upon level change
void Fighter::levelUp() {
  level++;
  hpChange();
  setAttackBonus();
  getDamageBonus();
  getAttacksPerRound();
  notify();
}

//! Implementation of stats generator
//! @return total: random number generated
int Fighter::generateStats() {
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

  for (int i = 0; i < 4; i++) {
    score = rand(gen);;
    diceTurns[i] = score;

    if (diceTurns[i] < lowest) {
      lowest = diceTurns[i];
    }
    total += diceTurns[i];
  }
  total -= lowest;

  level = 1;

  return total;
}


//! Implementation of save Fighter
//! @param saves Fighter into txt file.
/*void Fighter::saveCharacter()
{
	string type = "";
	string saveFile;
	cout << "Enter name of file being saved: ";
	cin >> saveFile;



	ofstream ofs(saveFile);
	ofs << "CharFile" << endl;	//define type of save file
	ofs << getCharacterType() << endl;
	ofs << level << endl;
	ofs << currentHitPoints << endl;
	ofs << getStrength() << endl;
	ofs << getDexterity() << endl;
	ofs << getConstitution() << endl;
	ofs << getIntelligence() << endl;
	ofs << getWisdom() << endl;
	ofs << getCharisma() << endl;
//	for (int i = 0; i < 6; i++)
//		ofs << abilityScores[i] << endl;
	ofs << armorModifier() << endl;
	//ofs << getDamageBonus() << endl;
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



}*/

//! Implementation of load Fighter
//! @param loads Fighter from txt file.
/*void Fighter::loadCharacter()
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

	ifs >> characterType;
	ifs >> level;
	ifs >> currentHitPoints;
	for (int i = 0; i < 6; i++) {
		ifs >> abilityScores[i];
	}
	ifs >> armor;
	//ifs >>
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
}*/

//! Implementation of player info
//! @param print Fighter info on screen
void Fighter::playerInfo() {
  cout << "-------------------------------\n";
  cout << "Class Type: " << characterType << endl;
  cout << "Level: " << level << endl;
  cout << "Total HP: " << currentHitPoints << endl;
  cout << "Total armor: " << armorModifier() << endl;
  cout << "Strenght: " << getStrength() << endl;
  cout << "Dexterity: " << getDexterity() << endl;
  cout << "Constituion: " << getConstitution() << endl;
  cout << "Intelect: " << getIntelligence() << endl;
  cout << "Wizdom: " << getWisdom() << endl;
  cout << "Charisma: " << getCharisma() << endl;
  cout << "Damange bonus: " << getDamageBonus() << endl;
  cout << "Attack bonus: ";
  if (attacksPerRound > 1) {
    for (int i = 0; i < attacksPerRound; i++) {
      cout << *(bonusAttack + i) << " ; ";
    }
    cout  << endl;
  } else
    cout << *(bonusAttack + 0) << " ";


  cout << "Attacks per/round: " << getAttacksPerRound() << endl;
  cout << "-------------------------------\n";
  if (ChLogger::isOn()) {
    ChLogger::fout() << "-------------------------------\n";
    ChLogger::fout() << "Class Type: " << getCharacterType() << endl;
    ChLogger::fout() << "Level: " << getLevel() << endl;
    ChLogger::fout() << "Total HP: " << currentHitPoints << endl;
    ChLogger::fout() << "Ability scores: ";
    ChLogger::fout() << " Strength: " << getStrength();
    ChLogger::fout() << " , Dexterity: " << getDexterity();
    ChLogger::fout() << " , Constitution: " << getConstitution();
    ChLogger::fout() << " , Intellect: " << getIntelligence();
    ChLogger::fout() << " , Wisdom: " << getWisdom();
    ChLogger::fout() << " , Charisma: " << getCharisma();
    ChLogger::fout() << endl;
    ChLogger::fout() << "Damage bonus: " << getDamageBonus() << endl;
    ChLogger::fout() << "Attacks per Round: " << getAttacksPerRound() << endl;


    ChLogger::fout() << "-------------------------------\n";
  }
}

//! Implementation of printBackPackItems
//! @param prints backpack items on screen
void Fighter::printBackPackItems() {
  backpack.printBackpack();
}

ItemContainer Fighter::getBackPack() {
  return backpack;
}

//! Implementation of addToBackPack
//! @param takes in an item and adds item to backpack
void Fighter::addToBackpack(Item* newItem) {
  backpack.addItem(newItem);
}

//! Implementation of mutator method of setPositionX
//! @param sets position X of Fighter
void Fighter::setPositionX(int x) {
  positionX = x;
}

//! Implementation of mutator method of  setPositionY
//! @param sets position Y of Fighter
void Fighter::setPositionY(int y) {
  positionY = y;
}

//! Implementation of accessor method getPositionX
//! @return positionX: gets position X of Fighter
int Fighter::getPositionX() {
  return positionX;
}

//! Implementation of accessor method getPositionY
//! @return positionY: gets position Y of Fighter
int Fighter::getPositionY() {
  return positionY;
}

Item* Fighter::unEquip(string s) {
  return nullptr;
}

Item* Fighter::retrieveItem(string s) {
  return nullptr;
}

bool Fighter::isEquiped(string s) {
  return false;
}

//! Implementation of printEquippedItems
//! @param prints every item equipped onto screen
void Fighter::printEquippedItems() {
  cout << endl;
}


void Fighter::combat(Character* monster) {
  int totalDmg;
  /*
  	for (int i = 0; i < attacksPerRound; i++)
  	{
  		//roll dice for dmg
  		int roll = diceRoll(20);

  		switch (attacksPerRound)
  		{
  			case 1:
  			{
  					playertotalDmg = bonusAttack[0] + getDamageBonus() + roll;
  					monsterTotDmg = monster->get
  					cout << "First blow: " << totalDmg << "dmg" << endl;
  					 monster->hit(totalDmg);
  			}break;

  			case 2:
  			{
  					  totalDmg = bonusAttack[1] + getDamageBonus() + roll;
  					  cout << "Second blow: " << totalDmg << "dmg" << endl;
  					   monster->hit(totalDmg);
  			}break;
  			case 3:
  			{
  					  totalDmg = bonusAttack[2] + getDamageBonus() + roll;
  					  cout << "Third blow: " << totalDmg << "dmg" << endl;
  					  monster->hit(totalDmg);
  			}break;
  			case 4:
  			{
  					  totalDmg = bonusAttack[3] + getDamageBonus() + roll;
  					  cout << "Forth blow: " << totalDmg << "dmg" << endl;
  					  monster->hit(totalDmg);
  			}break;

  		}
  	}
  */

}
