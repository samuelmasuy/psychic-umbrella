//! @file
//! @brief Implementation file for the Item class
//!
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#include "Item.h"

//! default constructor
Item::Item() {
  type = "";
}

//! constructor that receives an item type as a string and a vector containing the enhancements that this item gives
//! @param type_name : string representing the type of item
//! @param influences : vector containing all the characteristics influenced by the item
Item::Item(string type_name, vector<Enhancement> influences) {
  // ***todo***: this constructor should verify that an new item of a certain type only
  // enhances a character statistic valid for this item type
  type = type_name;
  influence = influences;
}

//! method to get the type of the item
//! @return : type of the item
string Item::getType() {
  return type;
}

//! method to get the influences of the item
//! @return : vector containg the list of stats that the item enhances
vector<Enhancement> Item::getInfluences() {
  return influence;
}

//! method to validate an item, e.g. verify that an new item of a certain type only enhances a character statistic valid for this item type
//! @return : true if the enhancement list is valid according to the rules, false if not
bool Item::validateItem() {
  std::map<std::string, std::vector<string> > m;
  string helmet[] = { "intelligence", "wisdom", "armor" };
  m["helmet"] = vector<string>(helmet, std::end(helmet));
  string armor[] = { "armor" };
  m["armor"] = vector<string>(armor, std::end(armor));
  string shield[] = { "armor" };
  m["shield"] = vector<string>(shield, std::end(shield));
  string ring[] = { "armor", "strength", "constitution", "wisdom", "charisma" };
  m["ring"] = vector<string>(ring, std::end(ring));
  string belt[] = { "constitution", "strength" };
  m["belt"] = vector<string>(belt, std::end(belt));
  string boots[] = { "armor", "dexterity" };
  m["boots"] = vector<string>(boots, std::end(boots));
  string weapon[] = { "attack", "damage" };
  m["weapon"] = vector<string>(weapon, std::end(weapon));

  std::string type_copy = type.c_str();
  std::transform(type_copy.begin(), type_copy.end(), type_copy.begin(), ::tolower); //lowercase
  std::map<string, std::vector<string> >::iterator it = m.find(type_copy);
  if ( it == m.end() ) {
    // not found
    cout << "Type not found";
    return false;
  }
  vector<string> found = it->second;

  for (auto inf: influence) {
    std::string enhancement_type = inf.getType();
    std::transform(enhancement_type.begin(), enhancement_type.end(), enhancement_type.begin(), ::tolower); //lowercase
    if ( std::find(found.begin(), found.end(), enhancement_type) == found.end() ) {
      cout << "Enhancement type not valid";
      return false;
    }
    if (inf.getBonus() < 1 || inf.getBonus() > 5) {
      cout << "Enhancement bonus not valid";
    }
  }

  return true;
}
