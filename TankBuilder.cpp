,include "TankBuilder.h"
#include <iostream>
using namespace std;

TankBuilder::TankBuilder() {
}

TankBuilder::~TankBuilder() {
}

void TankBuilder::buildAbilityMods() {
  int* newAbilityScores;
  int tankHP;
  newAbilityScores = myCharacter->getAbilityScores();

  int oldAbilityScores[6]= {};

  for(int i=0; i<6; i++) {
    oldAbilityScores[i]=newAbilityScores[i];
  }

  int temp = 0;
  for(int i=0; i<6; i++) {
    for(int j=0; j<5; j++) {
      if(oldAbilityScores[j+1]>oldAbilityScores[j]) {
        temp = oldAbilityScores[j+1];
        oldAbilityScores[j+1] = oldAbilityScores[j];
        oldAbilityScores[j] = temp;
      }
    }
  }

  newAbilityScores[0] = oldAbilityScores[2];
  newAbilityScores[1] = oldAbilityScores[1];
  newAbilityScores[2] = oldAbilityScores[0];
  newAbilityScores[3] = oldAbilityScores[3];
  newAbilityScores[4] = oldAbilityScores[5];
  newAbilityScores[5] = oldAbilityScores[4];
  myCharacter->hpChange();
  myCharacter->setArmor();

}
void TankBuilder::buildType() {
  myCharacter->setCharacterType("Tank");
}
