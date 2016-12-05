#pragma once
#include "Character.h"
#include "Fighter.h"


class CharacterBuilder {
 public:
  Character* getCharacter() {
    return myCharacter;
  }
  void createNewCharacter() {
    myCharacter = new Fighter;
  }
  virtual void buildAbilityMods() = 0;
  virtual void buildType() = 0;

 protected:
  Character* myCharacter;
};
