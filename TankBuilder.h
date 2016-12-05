/*
 * TankBuilder.h
 *
 *  Created on: Nov 21, 2016
 *      Author: ahmad
 */
#pragma once

#include "CharacterBuilder.h"

class TankBuilder: public CharacterBuilder {
 public:
  TankBuilder();
  virtual ~TankBuilder();
  virtual void buildAbilityMods();
  virtual void buildType();
};
