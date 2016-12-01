#pragma once
#include "Strategy.h"
#include "Map.h"

class AggressiveStrategy : public Strategy
{
public:
	AggressiveStrategy();
	~AggressiveStrategy();
	void execute() {
		inputMap->getPlayerPos();
		inputMap->setMonsterPos();
		combat(inputMapGetPlayer());
	};

private:

};