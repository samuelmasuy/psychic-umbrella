#pragma once
#include <iostream>
#include "CharacterBuilder.h"

class NimbleBuilder: public CharacterBuilder {
 public:
  NimbleBuilder();
  virtual ~NimbleBuilder();
  virtual void buildAbilityMods();
  virtual void buildType();
};
