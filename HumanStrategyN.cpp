#include "HumanStrategyN.h"



HumanStrategyN::HumanStrategyN()
{
}


HumanStrategyN::~HumanStrategyN()
{
}

void HumanStrategyN::execute(GameStateN* inputGameState){
	Character* mainCharacter = inputGameState->getMainCharacter();
	Map* map = inputGameState->getMap();
	vector<Character*> monsters = inputGameState->getMonsters();
	vector<Chest*> chests = inputGameState->getChests();

	int xCoordinate;
	int yCoordinate;

	cout << "Indicate the x coordiante of where you would like to move to?";
	cin >> xCoordinate;
	cout << "Indicate the y coordinate of where you woud like to move to?";
	cin >> yCoordinate;

	vector<Coord2D> location = checkAdjacentCell(xCoordinate, yCoordinate, map, CHAR_EMPTY);
	if (location[0].x > 0) {}

}
