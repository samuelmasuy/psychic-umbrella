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

using namespace std;

// Definitions of helper functions
int validate_choice(int, int);
string get_filename();
bool has_ending(string const &, string const &);

int main(int argc, char const* argv[]) {
  cout << "Dungeons And Dragons Game" << endl;

  Character* character = NULL;
  cout << "Let's create a character, would you like to play with a fighter[1] or a regular character[2]: " << endl;
  int character_choice = validate_choice(1, 2);
  switch (character_choice) {
  case 1:
    character = new Fighter();
  case 2:
    character = new Character();
  }

  // Create a character
  // CharacterDirector* cd = new CharacterDirector();
  // cd->setCharacterBuilder(new Warrior());
  // cd->createNewCharacter("Umbrella");
  // Character* character = cd->getCharacter();

  // create items
  ItemDirector* id = new ItemDirector();
  id->setItemBuilder(new RandomBuilder());
  id->makeItem();
  Item* item = id->getItem();
  cout << "Here is a new Item: " << endl;
  item->printItem();
  cout << endl;

  cout << "Would you like to edit this item? ('y'/'n'): ";
  char choice;
  cin >> choice;
  if (choice == 'y') {
    item->editItem();
    //item->saveItem();
  }

  cout << "Would you like your character to be equiped with this item? ('y'/'n'): ";
  cin >> choice;
  if (choice== 'y') {
    character->equipItem(item);
  }
  delete id;

  cout << "Here are the stats of your character" << endl;
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

Map map;
  char filename[240];
  do {
    cout << "Indicate map name --> ";
    cin.getline(filename, 240);
    NormalizeString(filename);
    MapDirector d;

    // load map from file
    MapBuilderB mb;
    if (mb.LoadMap(filename, 1))
      continue;
   

    // set this builder to director
    d.SetBuilder(&mb);
    // get the map from director
    d.GetMap(map);
	break;
  } while (true);

  map.Display();

  GameBuilder* gb = new GameBuilder();
  gb->constructGame();
  gb->setCharacterAndMap(character, &map);
  Game* game = gb->getGame();
  game->play();

  return 0;
}

int validate_choice(int min, int max) {
  while (true) {
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
    return (0 == str.compare (str.length() - ending.length(), ending.length(), ending));
  } else {
    return false;
  }
}

