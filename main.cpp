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
#include "Logger.h"
#include "Screen.h"

using namespace std;

// Definitions of helper functions
int validate_choice(int, int);
string get_filename();
bool has_ending(string const &, string const &);

int main(int argc, char const* argv[]) {
  Character* character = nullptr;
  //Character* monster = NULL;
  CharacterBuilder* cb = nullptr;

  CharacterDirector* cd = new CharacterDirector();
  while (!screen::checkConsoleSize(150, 250)) {
    std::cout << "Console buffer needs to be set to the following settings: " << std::endl;
    std::cout << "Screen Buffer Size: " << std::endl;
    std::cout << "\tWidth: 150" << std::endl;
    std::cout << "\tHeight: 250" << std::endl;
    system("pause");
  }
  screen::cls();

  screen::setCursorPosition(screen::COORD_INI_GAME_SCREEN);

  cout << "o.OOOo.                                                                        o      o.OOOo.                                          " << endl;
  cout << " O    `o                                                                      O        O    `o                                         " << endl;
  cout << " o      O                                                                     o        o      O                                        " << endl;
  cout << " O      o                                                                     o        O      o                                        " << endl;
  cout << " o      O O   o  'OoOo. .oOoO .oOo. .oOo. 'OoOo. .oOo       .oOoO' 'OoOo. .oOoO        o      O `OoOo. .oOoO' .oOoO .oOo. 'OoOo. .oOo  " << endl;
  cout << " O      o o   O   o   O o   O OooO' O   o  o   O `Ooo.      O   o   o   O o   O        O      o  o     O   o  o   O O   o  o   O `Ooo. " << endl;
  cout << " o    .O' O   o   O   o O   o O     o   O  O   o     O      o   O   O   o O   o        o    .O'  O     o   O  O   o o   O  O   o     O " << endl;
  cout << " OooOO'   `OoO'o  o   O `OoOo `OoO' `OoO'  o   O `OoO'      `OoO'o  o   O `OoO'o       OooOO'    o     `OoO'o `OoOo `OoO'  o   O `OoO' " << endl;
  cout << "                            O                                                                                     O                    " << endl;
  cout << "                         OoO'                                                                                  OoO'                    " << endl;

  screen::setCursorPosition(screen::COORD_INI_OBSERVER_SCREEN);

  /*
  cout << endl << "Do you want to load your character from a file?";
  cin >> choice;
  if (choice == 'y') {
  	loadCharacter();

  }
  else
  {
  */

  screen::setCursorPosition(screen::COORD_INI_OBSERVER_SCREEN);
  cout << "Let's create a character, would you like to play with a nimble[1], a tank[2], or a bully[3]: " << endl;

  int character_choice = validate_choice(1, 3);
  switch (character_choice) {
  case 1:
    cb = new NimbleBuilder();
    cd->setCharacterBuilder(cb);
    cd->constructCharacter();
    character = cd->getCharacter();
    delete cb;
    break;
  case 2:
    cb = new TankBuilder();
    cd->setCharacterBuilder(cb);
    cd->constructCharacter();
    character = cd->getCharacter();
    delete cb;
    break;
  case 3:
    cb = new BullyBuilder();
    cd->setCharacterBuilder(cb);
    cd->constructCharacter();
    character = cd->getCharacter();
    delete cb;
    break;
  }
  delete cd;

  // for (int i = 0; i < 16; i++) {
  //   character->levelUp();
  // }
  cout << "Here is your character stats:" << endl;
  character->playerInfo();
  system("pause");

  screen::clsObserver();

  char choice;

  cout << "Let's create an item!" << endl;
  // create items
  ItemDirector* id = new ItemDirector();
  id->setItemBuilder(new RingBuilder());
  id->makeItem();
  Item* item = id->getItem();
  cout << "Here is the Item: " << endl;
  item->printItem();
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
    screen::clsObserver();
  }

  cout << "Would you like your character to be equiped with this item? ('y'/'n'): ";
  cin >> choice;
  if (choice == 'y') {
    character = new ItemDecorator(character, item);
  }
  delete id;

  cout << endl << "Equiped Items::" << endl;
  character->printEquippedItems();

  system("pause");

  screen::clsObserver();

  cout << "Here are the stats of your character" << endl;
  character->playerInfo();

  system("pause");

  screen::clsObserver();

  //cout << "Unequiping the ring::" << endl;
  //Item* r = character->unEquip("ring");
  //r->printItem();
  cout << endl;
  character->playerInfo();
  cout << endl;
  cout << endl << "Equiped Items::" << endl;
  character->printEquippedItems();
  cout << endl;
  character->printBackPackItems();
  cout << endl;

  system("pause");
  screen::clsObserver();

  // ........... many more items
  cout << "Let's take care of the map." << endl;

  // map management
  manageMap();

  screen::clsObserver();

  cout << "TIME TO PLAY" << endl;

  if (Logger::isOn()) Logger::fout() << "Game is going to be started" << endl;
  string campaignFilename = "";
  Campaign theCampaign;
  do {

    cout << "Please enter the Campaign you would like to play!: ";
    cin >> campaignFilename;
    if (theCampaign.Load(campaignFilename.c_str()) == 0) {
      break;
    }
    screen::clsObserver();
  } while (1);

  vector<int> levels;
  theCampaign.GetLevels(levels);
  GameBuilder* gb = nullptr;
  Game* game = nullptr;
  for (unsigned int i = 0; i < levels.size(); i++) {
    Map map;
    MapDirector d;

    // load map from file
    MapBuilderB mb;
    if (mb.LoadMap(theCampaign.GetFileName(levels[i]).c_str(), levels[i]))
      continue;
    if (Logger::isOn()) Logger::fout() << "Level #" << levels[i] << "(" << theCampaign.GetFileName(levels[i]).c_str() << ") has been loaded" << endl;

    // set this builder to director
    d.SetBuilder(&mb);
    // get the map from director
    d.GetMap(map);

    gb = new GameBuilder();
    gb->constructGame();
    gb->setCharacterAndMap(character, &map);
    game = gb->getGame();
    screen::clsObserver();

    cout << "The level is ready" << endl;

    system("pause");
    screen::clsObserver();

    game->play();
    cout << "Map Completed! Press (y) to continue to the next phase or (n) to exit!-->";
    cin >> choice;
    if (choice == 'y') {
      if (Logger::isOn()) Logger::fout() << "Moved to next Map!" << endl;
      screen::clsObserver();
      screen::clsGame();
      continue;
    }
    if (choice == 'n') {
      return 0;
    }

  }
  cout << "Game over!!! Press any key and then enter to exit! -->";
  if (Logger::isOn()) Logger::fout() << "Game is over" << endl;
  delete game;
  delete gb;
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
