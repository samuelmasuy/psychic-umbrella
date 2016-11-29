#pragma once
#include "CharacterBuilder.h"
#include <iostream>

using namespace std;

class CharacterDirector {
 public:
  CharacterDirector() {

  }
  ~CharacterDirector() {

  }
  void setCharacterBuilder(CharacterBuilder* chBldr) {

    myCharBuilder = chBldr;
  }

  Character* getCharacter() {
    return myCharBuilder->getCharacter();
  }
  void constructCharacter() {

    myCharBuilder->createNewCharacter();
    myCharBuilder->buildAbilityMods();
    myCharBuilder->buildType();
  }

 private:
  CharacterBuilder* myCharBuilder;
};
