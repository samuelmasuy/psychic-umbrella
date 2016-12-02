#include "CharacterOBS.h"
#include "Logger.h"
#include <iostream>
using namespace std;


CharacterOBS::CharacterOBS() {
}
CharacterOBS::CharacterOBS(Character* theCharacter) {
  character = theCharacter;
  character->attach(this);
}
void CharacterOBS::printPlayerInfo() {
  system("CLS");
  character->playerInfo();
}

void CharacterOBS::update() {
  printPlayerInfo();
}

CharacterOBS::~CharacterOBS() {
  character->detach(this);
}
