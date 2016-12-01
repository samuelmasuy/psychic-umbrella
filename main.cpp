/**
* @file main.cpp
* @brief Driver for d20 game.
*/
#include <iostream>
#include <string>
#include <fstream>

#include "MapManager.h"
#include "MapBuilder.h"
#include "ChestBuilder.h"
#include "Character.h"
#include "GameBuilder.h"
#include "Game.h"
#include "CharacterBuilder.h"
#include "NimbleBuilder.h"
#include "CharacterDirector.h"
#include "TankBuilder.h"
#include "BullyBuilder.h"
#include "CharacterDecorator.h"
#include "ItemDecorator.h"

using namespace std;

// Definitions of helper functions
int validate_choice(int, int);
string get_filename();
bool has_ending(string const &, string const &);

int main(int argc, char const* argv[]) {
  cout << "Dungeons And Dragons Game" << endl;

  Character* character = NULL;
  //Character* monster = NULL;
  CharacterBuilder* nimbleBuilder = NULL;
  CharacterBuilder* tankBuilder = NULL;
  CharacterBuilder* bullyBuilder = NULL;


  CharacterDirector* cd = new CharacterDirector();


  /*
  cout << endl << "Do you want to load your character from a file?";
  cin >> choice;
  if (choice == 'y') {
  	loadCharacter();

  }
  else
  {
  */

  cout << "Let's create a character, would you like to play with a nimble[1], a tank[2], or a bully[3]: " << endl;

  int character_choice = validate_choice(1, 3);
  switch (character_choice) {
  case 1:
    nimbleBuilder = new NimbleBuilder();
    cd->setCharacterBuilder(nimbleBuilder);
    cd->constructCharacter();
    character = cd->getCharacter();
    delete nimbleBuilder;
    break;
  case 2:
    tankBuilder = new TankBuilder();
    cd->setCharacterBuilder(tankBuilder);
    cd->constructCharacter();
    character = cd->getCharacter();
    delete tankBuilder;
    break;
  case 3:
    bullyBuilder = new BullyBuilder();
    cd->setCharacterBuilder(bullyBuilder);
    cd->constructCharacter();
    character = cd->getCharacter();
    delete bullyBuilder;
    break;
  }
  delete cd;

  // for (int i = 0; i < 16; i++) {
  //   character->levelUp();
  // }

  char choice;

  // create items
  ItemDirector* id = new ItemDirector();
  id->setItemBuilder(new RingBuilder());
  id->makeItem();
  Item* item = id->getItem();
  id->setItemBuilder(new BeltBuilder());
  id->makeItem();
  Item* item2 = id->getItem();
  cout << "Here is a new Item: " << endl;
  item->printItem();
  item2->printItem();
  cout << endl;

  cout << "Would you like to edit this item? ('y'/'n'): ";
  cin >> choice;
  if (choice == 'y') {
    item->editItem();
    cout << "Would you like to save this item? ('y'/'n'): ";
    cin >> choice;
    if (choice == 'y') {
      item->saveItem();
    }
  }

  cout << "Would you like your character to be equiped with this item? ('y'/'n'): ";
  cin >> choice;
  if (choice == 'y') {
    character->playerInfo();
    character = new ItemDecorator(character, item);
    character = new ItemDecorator(character, item2);
    cout << endl << "Equiped Items::" << endl;
    character->printEquippedItems();
  }
  delete id;

  cout << "Here are the stats of your character" << endl;
  character->playerInfo();

  Item* r = character->unEquip("ring");
  r->printItem();
  cout << endl;
  character->playerInfo();
  cout << endl;
  character->printEquippedItems();
  cout << endl;
  character->printBackPackItems();
  cout << endl;

  // ........... many more items
  cout << "Let's take care of the map." << endl;

  // map management
  manageMap();

  cout << endl;

  cout << "TIME TO PLAY" << endl;
  string campaignFilename = "";
  Campaign theCampaign;
  do {

    cout << "Please enter the Campaign you would like to play!: ";
    cin >> campaignFilename;
    if (theCampaign.Load(campaignFilename.c_str()) == 0) {
      break;
    }
  } while (1);

  vector<int> levels;
  theCampaign.GetLevels(levels);
  for (unsigned int i = 0; i < levels.size(); i++) {
    Map map;
    MapDirector d;

    // load map from file
    MapBuilderB mb;
    if (mb.LoadMap(theCampaign.GetFileName(levels[i]).c_str(), levels[i]))
      continue;
    // set this builder to director
    d.SetBuilder(&mb);
    // get the map from director
    d.GetMap(map);


    GameBuilder* gb = new GameBuilder();
    gb->constructGame();
    gb->setCharacterAndMap(character, &map);
    Game* game = gb->getGame();
    game->play();
    delete game;
    delete gb;
  }
  cout << "Game over!!! Press any key and then enter to exit! -->";
  string aux;
  cin >> aux;
  return 0;
}

int validate_choice(int min, int max) {
  while (true) {
    //cin.ignore();
    cout << "Enter your choice: ";
    string s;
    getline(cin, s);
    char *endp = 0;
    int ret = strtol(s.c_str(), &endp, 10);
    if (endp != s.c_str() && !*endp && ret >= min && ret <= max) {
      return ret;
    }
    cout << "Invalid choice." << endl;
  }
}

string get_filename() {
  while (true) {
    cout << "Enter a map filename: " << endl;
    string s;
    getline(cin, s);
    ifstream file(s);
    if (file) {
      return s;
    }
    cout << "Invalid filename." << endl;
  }

}

bool has_ending(string const &str, string const &ending) {
  if (str.length() >= ending.length()) {
    return (0 == str.compare(str.length() - ending.length(), ending.length(), ending));
  } else {
    return false;
  }
}
