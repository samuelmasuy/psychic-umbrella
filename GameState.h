#pragma once
//#include "Character.h"
#include "Map.h"
#include "Monster.h"

class GameState{

public:
	//GameState();
	GameState(Character*, vector<Monster*>, Map*);
	void setMap(Map*);
	Map* getMap();
	void setMainCharacter(Character*);
	Character* getMainCharacter();
	void setMonsters(vector<Monster*>);
	vector<Monster*> getMonsters();
	

private:
	Character* mainCharacter;
	vector<Monster*> monsters;
	Map* map; 
};