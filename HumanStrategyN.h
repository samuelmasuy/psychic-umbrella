#pragma once
#include "StrategyN.h"

using namespace std;

class HumanStrategyN :
	public StrategyN
{
public:
	HumanStrategyN();
	~HumanStrategyN();
	void execute(GameStateN*);
};

