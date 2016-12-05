/*
 * MosnterBuilder.h
 *
 *  Created on: Nov 30, 2016
 *      Author: ahmad
 */

#pragma once
#include "Character.h"
#include "Monster.h"

namespace std {

class MonsterBuilder {
 public:
  Fighter* getMonster() {
    return myMonster;
  }
  void createNewMonster() {
    myMonster = new Monster;
  }
  virtual void buildType() = 0;

 protected:
  Fighter* myMonster;
};

} /* namespace std */
