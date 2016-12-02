#pragma once
#include "GameStateN.h"

class StrategyN
{
public:
	StrategyN();
	~StrategyN();
	virtual void execute(GameStateN*) = 0;
	bool checkCell(Coord2D*, Map*, char);
	Coord2D* identifyTargetCell(int, int, Map*, char);
	void combat(Character*, Character*);
	void move(Coord2D*, Map*, Character*);
};

