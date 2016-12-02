#include "StrategyN.h"



StrategyN::StrategyN()
{
}


StrategyN::~StrategyN()
{
}

bool StrategyN::checkCell(Coord2D* inputCoord, Map* inputMap, char type) {
	vector<Coord2D> outputLocation;
	if (inputMap->GetCell(inputCoord->x, inputCoord->y) == type) {
		return true;
	}
	else return false;
}

Coord2D* StrategyN::identifyTargetCell(int inputX, int inputY, Map* inputMap, char type){
	vector<Coord2D*> testCoords;
	testCoords.push_back(new Coord2D(inputX + 1, inputY + 1));
	testCoords.push_back(new Coord2D(inputX, inputY + 1));
	testCoords.push_back(new Coord2D(inputX -1, inputY + 1));
	testCoords.push_back(new Coord2D(inputX, inputY + 1));
	testCoords.push_back(new Coord2D(inputX, inputY - 1));
	testCoords.push_back(new Coord2D(inputX - 1, inputY + 1));
	testCoords.push_back(new Coord2D(inputX - 1, inputY));
	testCoords.push_back(new Coord2D(inputX - 1, inputY - 1));

	Coord2D* identifiedCoord = nullptr;

	for(int i = 0; i < testCoords.size(); i++){
		if (checkCell(testCoords[i], inputMap, type))
			return new Coord2D(testCoords[i]->x, testCoords[i]->y);
	}

	return identifiedCoord;
}

void StrategyN::move(Coord2D* targetLocation, Map* inputMap, Character* mover){
		char oldCellType = inputMap->GetCell(mover->getPositionX(), mover->getPositionY());
		inputMap->fillCell(mover->getPositionX(), mover->getPositionY(), CHAR_EMPTY);
		inputMap->fillCell(targetLocation->x, targetLocation->y, oldCellType);
		mover->setPositionX(targetLocation->x);
		mover->setPositionY(targetLocation->y);
}