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

}

bool HumanStrategyN::openChest(vector<Chest*> inputChests, Character* mainPlayer, Map* inputMap){
	Coord2D * locationOfChest = identifyTargetCell(mainPlayer->getPositionX(), mainPlayer->getPositionY(), inputMap, CHAR_CHEST);
	return true;
}
