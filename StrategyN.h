#pragma once
#include "GameStateN.h"

class StrategyN
{
public:
	StrategyN();
	~StrategyN();
	virtual void execute(GameStateN*) = 0;
	void combat(Character*, Character*);
	vector<Coord2D> checkAdjacentCell(int, int, Map*, char);
};

