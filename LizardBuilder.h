#pragma once
#include "MonsterBuilder.h"

class LizardBuilder :
  public MonsterBuilder {
 public:
  LizardBuilder();
  ~LizardBuilder();
  virtual void buildType();
};

