#include "FriendlyStrategyN.h"



FriendlyStrategyN::FriendlyStrategyN()
{
}


FriendlyStrategyN::~FriendlyStrategyN()
{
}

void FriendlyStrategyN::execute(GameStateN* inputGameState, Character* monster){
	Character* mainCharacter = inputGameState->getMainCharacter();
	Map* map = inputGameState->getMap();
	Character* theMonster = monster;
	vector<Character*> monsters = inputGameState->getMonsters();
	vector<Chest*> chests = inputGameState->getChests();
	
	cout << "I am a friendly monster, you go your way. I will go mine";

	srand(time(NULL));

	/* generate secret number between 1 and 10: */

	Coord2D* coordinates = new Coord2D(0, 0);

	bool stationary = true;
	while (stationary){

		
		
		// uniformly distributed in range (1, to # of Cols)
		coordinates->x = rand() % map->GetCols() + 1;
		coordinates->y = rand() % map->GetRows() + 1;

		stationary = moveMonster(coordinates, map, theMonster);
	}


}

bool FriendlyStrategyN::moveMonster(Coord2D* inputCoord, Map* inputMap, Character* monster){
	if (inputMap->GetCell(inputCoord->x + 1, inputCoord->y + 1) == CHAR_DOOR
		|| inputMap->GetCell(inputCoord->x - 1, inputCoord->y - 1) == CHAR_DOOR
		|| inputMap->GetCell(inputCoord->x + 1, inputCoord->y) == CHAR_DOOR
		|| inputMap->GetCell(inputCoord->x, inputCoord->y - 1) == CHAR_DOOR
		|| inputMap->GetCell(inputCoord->x, inputCoord->y + 1) == CHAR_DOOR
		|| inputMap->GetCell(inputCoord->x - 1, inputCoord->y) == CHAR_DOOR
		|| inputMap->GetCell(inputCoord->x - 1, inputCoord->y + 1) == CHAR_DOOR)
	{
		return true;
	}
	
	if (checkCell(inputCoord, inputMap, CHAR_EMPTY) || checkCell(inputCoord, inputMap, CHAR_ENTRY) || checkCell(inputCoord, inputMap, CHAR_DOOR))
	{

		move(inputCoord, inputMap, monster);
		return false;
	}

	else {
		return true;
	}
}