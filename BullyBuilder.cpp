#include "BullyBuilder.h"

BullyBuilder::BullyBuilder() {
}

BullyBuilder::~BullyBuilder() {
}

void BullyBuilder::buildAbilityMods() {
  int* newAbilityScores;
  newAbilityScores = myCharacter->getAbilityScores();

  int oldAbilityScores[6] = {};

  for (int i = 0; i < 6; i++) {
    oldAbilityScores[i] = newAbilityScores[i];
  }

  int temp = 0;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 5; j++) {
      if (oldAbilityScores[j + 1] > oldAbilityScores[j]) {
        temp = oldAbilityScores[j + 1];
        oldAbilityScores[j + 1] = oldAbilityScores[j];
        oldAbilityScores[j] = temp;
      }
    }
  }
  newAbilityScores[0] = oldAbilityScores[0];
  newAbilityScores[1] = oldAbilityScores[2];
  newAbilityScores[2] = oldAbilityScores[1];
  newAbilityScores[3] = oldAbilityScores[3];
  newAbilityScores[4] = oldAbilityScores[5];
  newAbilityScores[5] = oldAbilityScores[4];
  myCharacter->hpChange();
  myCharacter->setArmor();
}
void BullyBuilder::buildType() {
  myCharacter->setCharacterType("Bully");
}
