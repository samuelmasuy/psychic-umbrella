#pragma once
#include "Strategy.h"
#include "Map.h"
#include <iostream>

using namespace std;

class HumanStrategy : public Strategy
{

public:
	HumanStrategy();
	~HumanStrategy();
	void execute(*GameState);

private:

};