#include "AvatarSprite.h"


AvatarSprite::AvatarSprite() {
}


AvatarSprite::~AvatarSprite() {
}


AvatarSprite::AvatarSprite(Character* ch, StrategyN* strat) {
  c = ch;
  s = strat;
}

StrategyN* AvatarSprite::getStrategy() {
  return s;
}

Character* AvatarSprite::getCharacter() {
  return c;
}

void AvatarSprite::setStrategy(StrategyN* newS) {
  s = newS;
}
void AvatarSprite::setCharacter(Character* newC) {
  c = newC;
}

void AvatarSprite::execute(GameStateN* gameState) {
  s->execute(gameState, this->c);
}
