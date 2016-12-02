#pragma once

#include "MonsterBuilder.h"

class VineBuilder : public MonsterBuilder {
 public:
  VineBuilder();
  ~VineBuilder();
  virtual void buildType();
};
