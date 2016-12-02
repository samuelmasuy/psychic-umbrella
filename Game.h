/**
* @file Game.h
* @brief Definition of the Game walkthought.
*/
#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <map>
#include "Item.h"
#include "Character.h"
#include "Map.h"
#include "ChestBuilder.h"
#include "CharacterOBS.h"
#include "MapObserver.h"
#include "ChestDirector.h"
#include "DoorDirector.h"
#include "CharacterDecorator.h"
#include "MonsterDirector.h"
#include "ElfBuilder.h"
#include "GoblinBuilder.h"
#include "LizardBuilder.h"
#include "MedusaBuilder.h"
#include "SkeletonBuilder.h"
#include "VineBuilder.h"
#include "ItemDecorator.h"
#include "GameStateN.h"


using namespace std;

/**
* @brief Game Engine, it runs the game and interacts with the items, the
* characters and the map.
*/
class Game {
public:
	/**
	* @brief Start a new game.
	*/
	void play();

	/**
	* @brief Stop a new game.
	*/
	void stop();

	/**
	* @brief Set map for the game play.
	*
	* @param Map
	*/
	void setMap(Map*);

	/**
	* @brief Set the character for the game play.
	*
	* @param Character
	*/
	void setCharacter(Character*);

	/**
	* @brief Get map of the game.
	*
	* @return pointer to a Map.
	*/
	Map* getMap();

	/**
	* @brief Get character of the game.
	*
	* @return pointer to a character.
	*/
	Character* getCharacter();

	/**
	* @brief Print the game usage.
	*/
	void printGameUsage();

	void saveCharacter();
	void loadCharacter();
private:
	Map* _map;
	Character* character;
	Game* game;
	bool enemiesDefeated;
	void initializeCharacterPositionOnMap();
	vector<Item*> getCharacterEquipedItems();
	vector<Chest*> createChestsFromMap();
	vector<Character*> createMonstersFromMap();
	void move(int, int, int, int);

	/**
	* @brief Open the ndoor
	*
	* @return true if door was opened
	*/
	bool openDoor();

	/**
	* @brief Open a chest
	*
	* @return true if chest was opened
	*/
	bool openChest();
	/**
	* @brief Fight with a monster
	*/
	void fightMonster();
	ItemDirector* id;
};

/**
* @brief Helper Function to clear the screen
*/
/*void clear_screen() {
#ifdef WINDOWS
std::system("cls");
#else
// Assume POSIX
std::system("clear");
#endif
}
*/

