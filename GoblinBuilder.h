#pragma once
#include "MonsterBuilder.h"
class GoblinBuilder :
  public MonsterBuilder {
 public:
  GoblinBuilder();
  ~GoblinBuilder();
  virtual void buildType();
};

