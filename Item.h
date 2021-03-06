#pragma once
#include <string>
#include <vector>
#include "Enhancement.h"
using namespace std;

class Item {
 public:
  Item();
  // default constructor
  Item(string type, vector<Enhancement> influence);
  string getType();
  vector<Enhancement> getInfluences();
  bool validateItem();
  void setType(string);
  void setInfluences(Enhancement);
  void saveItem();
  void loadItem();
  void editItem();
  void printItem();
  //~Item();

 private:
  string type;
  vector<Enhancement> influence;
};
