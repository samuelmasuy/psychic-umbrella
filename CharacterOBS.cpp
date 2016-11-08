#include "CharacterOBS.h"
#include <iostream>
using namespace std;


CharacterOBS::CharacterOBS()
{
}
CharacterOBS::CharacterOBS(Character* theCharacter)
{
	character = theCharacter;
	character->attach(this);

}

void CharacterOBS::update()
{
	system("CLS");
	character->playerInfo();
	
}

CharacterOBS::~CharacterOBS()
{
	character->detach(this);
}
