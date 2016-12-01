#pragma once
#include "Character.h"
#include "GameState.h"

class Strategy
{
public:
	Strategy();
	~Strategy();
	virtual int execute(GameState*) = 0;

private:
	void combat(Character* monster);
};

