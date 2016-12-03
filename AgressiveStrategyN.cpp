#include "AgressiveStrategyN.h"


AgressiveStrategyN::AgressiveStrategyN()
{
}


AgressiveStrategyN::~AgressiveStrategyN()
{
}

void AgressiveStrategyN::execute(GameStateN* inputGameState, Character*  monster)
{
	Character* mainCharacter = inputGameState->getMainCharacter();
	Map* map = inputGameState->getMap();
	Character* theMonster = monster;
	vector<Character*> monsters = inputGameState->getMonsters();
	vector<Chest*> chests = inputGameState->getChests();

	cout << "I will avenge my ancestors!!" << endl;
	Coord2D* moveTo = identifyTargetCell(mainCharacter->getPositionX(), mainCharacter->getPositionY(), map, CHAR_EMPTY);

	if (moveTo == nullptr)
		cout << "You are surrounded!" << endl;
	else
	{
		moveMonster(moveTo, map, theMonster);
		screen::setCursorPosition(screen::COORD_INI_GAME_SCREEN);
		screen::clsGame();
		map->print();
		screen::setCursorPosition(screen::COORD_INI_OBSERVER_SCREEN);

		cout << "Current hit points for monster " << theMonster->getHitPoints() << endl;
		cout << "Current hit points for character " << mainCharacter->getHitPoints() << endl;
		combat(mainCharacter, theMonster);
		cout << "Current hit points for monster " << theMonster->getHitPoints() << endl;
		cout << "Current hit points for character " << mainCharacter->getHitPoints() << endl;
	}

}

bool AgressiveStrategyN::moveMonster(Coord2D* inputCoord, Map* inputMap, Character* monster){
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
	char monsterType = inputMap->GetCell(monster->getPositionX(), monster->getPositionY());

	if (checkCell(inputCoord, inputMap, CHAR_EMPTY) || checkCell(inputCoord, inputMap, CHAR_ENTRY) || checkCell(inputCoord, inputMap, CHAR_DOOR))
	{

		move(inputCoord, inputMap, monster, monsterType);
		return false;
	}

	else {
		return true;
	}
}
