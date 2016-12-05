#pragma once
#include "MonsterBuilder.h"
class ElfBuilder :
  public MonsterBuilder {
 public:
  ElfBuilder();
  ~ElfBuilder();
  virtual void buildType();
};

