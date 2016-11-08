/**
 * @file main.cpp
 * @brief Driver for d20 game.
 */
#include <iostream>
#include <string>
#include <fstream>

#include "MapBuilder.h"
#include "ChestBuilder.h"
#include "CharacterBuilder.h"
#include "GameBuilder.h"
#include "Game.h"

using namespace std;

// Definitions of helper functions
int validate_choice(int, int);
string get_filename();
bool has_ending(string const &, string const &);

void main() {
  cout << "Dungeons And Dragons Game" << endl;

  // Create a character
  CharacterDirector* cd = new CharacterDirector();
  cd->setCharacterBuilder(new Warrior());
  cd->createNewCharacter("Umbrella");
  Character* character = cd->getCharacter();

  // create items
  ItemDirector* id = new ItemDirector();
  id->setArmorBuilder(new ConcreteArmorBuilder());
  id->constructArmor("name");
  // ........... many more items
  player->setInventoryItem(id->getArmor());


  cout << "You can chose one of the following option: " << endl;
  cout << "1. Play a predefined game" << endl;
  cout << "2. Play a custom game" << endl;
  cout << "3. Edit a map" << endl;

  int choice = validate_choice(1, 3);

  switch (choice) {
  case 1:
    MapDirector* md = new MapDirector();
    md->setMapBuilder(new ConcreteMapBuilder());
    md->constructMap();
    Map* map = mg->getMap()

               GameBuilder* gb = new GameBuilder();
    gb->constructGame();
    gb->setCharacterAndMap(player, map);
    Game* game = gb->getGame();
    game->play();

    delete gb;
    gb = NULL;
    delete md;
    md = NULL;
    break;
  case 3:
    string filename = get_filename();

    Map* map = new Map(filename);

    GameBuilder* gb = new GameBuilder();
    gb->constructGame();
    gb->setCharacterAndMap(player, map);
    Game* game = gb->getGame();
    game->play();

    delete gb;
    gb = NULL;
  case 3:
    cout << "Enter a map name: " << endl;
    string name;
    getline(cin, name);
    MapEditor* editor = new MapEditor(name);
    break;
  }
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
    if (file && has_ending(s, "map")) {
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

