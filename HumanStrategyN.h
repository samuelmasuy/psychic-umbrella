#pragma once
#include "GameStateN.h"
#include "ItemDecorator.h"
#include "DiceRoller.h"
#include "Monster.h"
#include "Map.h"
#include "Chest.h"

using namespace std;

class HumanStrategyN {
public:
	HumanStrategyN();
	~HumanStrategyN();
	void execute(GameStateN*);
	bool openChest(vector<Chest*>, Character*, Map*);
	bool combat(Character*, vector<Character*>, Map*);
};

