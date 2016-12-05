#pragma once
#include "MonsterBuilder.h"
#include <iostream>

using namespace std;

class MonsterDirector {
 public:
  MonsterDirector() {

  }
  ~MonsterDirector() {

  }
  void setMonsterBuilder(MonsterBuilder* chBldr) {

    myMonsterBuilder = chBldr;
  }

  Fighter* getMonster() {
    return myMonsterBuilder->getMonster();
  }
  void constructMonster() {

    myMonsterBuilder->createNewMonster();
    myMonsterBuilder->buildType();
  }

 private:
  MonsterBuilder* myMonsterBuilder;
};
