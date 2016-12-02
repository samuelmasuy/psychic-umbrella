#include "FriendlyStrategyN.h"



FriendlyStrategyN::FriendlyStrategyN()
{
}


FriendlyStrategyN::~FriendlyStrategyN()
{
}

void FriendlyStrategyN::execute(GameStateN* inputGameState){
	Character* mainCharacter = inputGameState->getMainCharacter();
	Map* map = inputGameState->getMap();
	vector<Character*> monsters = inputGameState->getMonsters();
	vector<Chest*> chests = inputGameState->getChests();
	

	bool stationary = true;
	while (stationary){
		cout << "I am a friendly monster, you go your way. I will go mine";


		stationary = moveMonster();
	}


}

bool FriendlyStrategyN::moveMonster(Coord2D* inputCoord, Map* inputMap, Character* monster){
	if (checkCell(inputCoord, inputMap, CHAR_EMPTY) || checkCell(inputCoord, inputMap, CHAR_ENTRY) || checkCell(inputCoord, inputMap, CHAR_DOOR))
	{
		move(inputCoord, inputMap, monster);
		return false;
	}

	else {
		return true;
	}
}