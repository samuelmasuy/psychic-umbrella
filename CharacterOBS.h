#pragma once
#include "Character.h"
#include "Observer.h"
class CharacterOBS : public Observer
{
public:
	CharacterOBS();
	CharacterOBS(Character* theCharacter);
	virtual ~CharacterOBS();
	void printPlayerInfo();
	void update();
private:
	Character* character;
};

