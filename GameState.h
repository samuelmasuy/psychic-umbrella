#pragma once
#include "Character.h"
#include "Map.h"
#include <vector>

class GameState{
public:
	GameState();
	GameState(Character*, vector<Character*>, Map*);
	~GameState();
	void setMap(Map*);
	Map* getMap();
	void setMainCharacter(Character*);
	Character* getMainCharacter();
	void setMonsters(vector<Character*>);
	vector<Character*> getMonsters();
	

private:
	Character* mainCharacter;
	vector<Character*> monsters;
	Map* map
};