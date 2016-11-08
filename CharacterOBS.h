#pragma once
#include "Character.h"
#include "Observer.h"
class CharacterOBS : public Observer
{
public:
	CharacterOBS();
	CharacterOBS(Character* theCharacter);
	virtual ~CharacterOBS();
	void update();
private:
	Character* character;
};

