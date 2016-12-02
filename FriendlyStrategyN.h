#pragma once
#include "StrategyN.h"

class FriendlyStrategyN : public StrategyN
{
public:
	FriendlyStrategyN();
	~FriendlyStrategyN();
	void execute(GameStateN*);
	bool moveMonster(Coord2D*, Map*, Character*);
};