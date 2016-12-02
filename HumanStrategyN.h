#pragma once
#include "GameStateN.h"
#include "ItemDecorator.h"
#include "DiceRoller.h"
#include "Monster.h"
#include "Map.h"
#include "Chest.h"
#include "StrategyN.h"

using namespace std;

class HumanStrategyN : public StrategyN {
public:
	HumanStrategyN();
	~HumanStrategyN();
	void execute(GameStateN*);
	bool openChest(Character*, Chest*, Map*);
	Character* monsterPresence(Character*, vector<Character*>, Map*);
	Chest* chestPresence(Character*, vector<Chest*>, Map*);
	bool combat(Character*, Character*);
};

