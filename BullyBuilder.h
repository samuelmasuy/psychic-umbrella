#pragma once
#include "CharacterBuilder.h"

class BullyBuilder: public CharacterBuilder {
 public:
  BullyBuilder();
  virtual ~BullyBuilder();
  virtual void buildAbilityMods();
  virtual void buildType();
};

