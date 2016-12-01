#include "HumanStrategy.h"

Strategy::Strategy()
{
}


Strategy::~Strategy()
{
}

int Strategy::execute(GameState* inputGameState){
	
	GameState* gameState = inputGameState;
	Character* mainCharacter = gameState->getMainCharacter();
	vector<Character*> monsters = gameState->getMonsters();
	Map* map = gameState->getMap();

	cout << "Specify the X coordianate of where you would like to move?";
	int xPosition;
	cin >> xPosition;
	cout << "Specify the Y coordinate of where you would like to move?";
	int yPosition;
	cin >> yPosition;
	if (map->ValidPos(xPosition, yPosition) && ((map->GetCell==CHAR_DOOR || map->GetCell==CHAR_EMPTY 
		|| map->GetCell==CHAR_ENTRY || map->GetCell==CHAR_EXIT))){
		mainCharacter->setPositionX(xPosition);
		mainCharacter->setPositionY(yPosition);
	}
	
	cout << "Would you like to open a chest?";
	bool attack;
	cin >> attack;

	cout << "Would you like to attack?"
}