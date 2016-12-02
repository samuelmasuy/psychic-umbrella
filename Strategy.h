#pragma once
#include "GameState.h"

class Strategy
{
public:
	Strategy();
	~Strategy();
	virtual int execute(GameState*) = 0;

private:
	void combat(Character* monster);
	vector<int> checkAdjacentCell(int, int, Map*);
};

