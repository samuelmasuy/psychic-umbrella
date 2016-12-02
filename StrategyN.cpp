#include "StrategyN.h"



StrategyN::StrategyN()
{
}


StrategyN::~StrategyN()
{
}

vector<Coord2D> StrategyN::checkAdjacentCell(int inputX, int inputY, Map* inputMap, char type) {
	vector<Coord2D> outputLocation;
	if (inputMap->ValidPos(inputX, inputY + 1) && inputMap->GetCell(inputX, inputY + 1) == type) {
		outputLocation.push_back(Coord2D(inputX, inputY + 1));
	}
	else if (inputMap->ValidPos(inputX, inputY - 1) && inputMap->GetCell(inputX, inputY - 1) == type) {
		outputLocation.push_back(Coord2D(inputX, inputY - 1));
	}
	else if (inputMap->ValidPos(inputX + 1, inputY) && inputMap->GetCell(inputX + 1, inputY) == type) {
		outputLocation.push_back(Coord2D(inputX + 1, inputY));
	}
	else if (inputMap->ValidPos(inputX - 1, inputY) && inputMap->GetCell(inputX - 1, inputY) == type) {
		outputLocation.push_back(Coord2D(inputX - 1, inputY));
	}
	else {
		outputLocation.push_back(Coord2D(-1, -1));
	}
	return outputLocation;
}

void combat(Character*, Character*){

}