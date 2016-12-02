#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include "Item.h"

using namespace std;

Item::Item() {
  type = "";
}

Item::Item(string type_name, vector<Enhancement> influences) {
  type = type_name;
  influence = influences;
}


string Item::getType() {
  return type;
}


vector<Enhancement> Item::getInfluences() {
  return influence;
}

bool Item::validateItem() {

  std::map<std::string, std::vector<string>> m;

  string helmet[] = { "intelligence","wisdom","armor" };
  m["helmet"] = vector<string>(helmet, std::end(helmet));

  string armor[] = { "armor" };
  m["helmet"] = vector<string>(armor, std::end(armor));

  string shield[] = { "armor" };
  m["shield"] = vector<string>(shield, std::end(shield));

  string ring[] = { "armor", "strength", "constitution", "wisdom", "charisma" };
  m["ring"] = vector<string>(ring, std::end(ring));

  string belt[] = { "strength", "constitution"};
  m["belt"] = vector<string>(belt, std::end(belt));

  string boots[] = { "armor", "dexterity" };
  m["boots"] = vector<string>(boots, std::end(boots));

  string weapon[] = { "attack", "damage" };
  m["weapon"] = vector<string>(weapon, std::end(weapon));

  std::string type_copy = type.c_str();
  std::transform(type_copy.begin(), type_copy.end(), type_copy.begin(), ::tolower); //lowercase
  std::map<string, std::vector<string> >::iterator it = m.find(type_copy);

  if (it == m.end()) {
    cout << "type not found" << endl;
    return false;

  }

  vector<string> found = it->second;

  for (auto inf : influence) {
    std::string enhancement_type = inf.getType();
    std::transform(enhancement_type.begin(), enhancement_type.end(), enhancement_type.begin(), ::tolower); //lowercase
    if (std::find(found.begin(), found.end(), enhancement_type) == found.end()) {
      cout << "Enhancement type not valid";
      return false;
    }
    if (inf.getBonus() < 1 || inf.getBonus() > 5) {
      cout << "Enhancement bonus not valid";
    }
  }

  return true;
}

void Item::setType(string newType) {
  type = newType;
}
void Item::setInfluences(Enhancement newEnhancement) {
  influence.insert(influence.begin(), newEnhancement);
}

//save an item to file
void Item::saveItem() {
  string fileName;
  int numberOfInfluences = influence.size();
  cout << "File Name: ";
  cin >> fileName;

  ofstream output(fileName);

  output << "ItemFile" << endl;	//type of save
  output << type << endl;			//item type

  output << numberOfInfluences << endl;
  for (int i = 0; i < numberOfInfluences; i++) {
    output << influence.at(i).getType() << endl;
    output << influence.at(i).getBonus() << endl;
  }
  output.close();
}

//load item from file
void Item::loadItem() {
  string fileName;
  string enhanceType;
  string Validation;
  Enhancement *tempEnhance;
  int numberOfInfluences;
  int bonus;
  bool badFile = false;
  cout << "Load File: ";
  cin >> fileName;

  ifstream input(fileName);
  do {
    while (!input.good()) {
      cout << "File does not exist, try again: ";
      cin >> fileName;
      input.open(fileName);
    }
    input >> Validation;
    if (Validation == "ItemFile")//check if file is for item
      badFile = true;
    else {
      input.close();
      badFile = false;
      cout << "Incorrect File Loaded, select another File: " << endl;
      cin >> fileName;
      input.open(fileName);
    }
  } while (badFile == false);

  input >> type;						//type of item
  input >> numberOfInfluences;		//how many influences (dexterity +3, strenght +4, etc)

  for (int i = 0; i < numberOfInfluences; i++) {
    input >> enhanceType;					//type enhacement dexterity, wisdomt etc
    input >> bonus;					//bonus +3,+4 etc
    tempEnhance = new Enhancement(enhanceType, bonus);
    influence.insert(influence.begin(), *tempEnhance);
    delete tempEnhance;
  }
  input.close();
}

void Item::printItem() {
  cout << endl << "Item Type: " << type << endl;
  for (int i = 0; i < influence.size(); i++) {
    cout << " {" << influence[i].getType() << " +" << influence[i].getBonus() << "}";
  }
}

void Item::editItem() {
  string enhacementType;
  int bonus;

  cout << "Here is the current item" << endl;
  printItem();
  cout << " Enter enhacement you want to set: ";
  cin >> enhacementType;
  cout << endl;
  cout << " Enter bonus for the enhacement: ";
  cin >> bonus;
  for (int i = 0; i < influence.size(); i++) {
    influence[i].setEnhancement(enhacementType, bonus);
    validateItem();
  }
}
