#pragma once
#include "MonsterBuilder.h"
class SkeletonBuilder :
  public MonsterBuilder {
 public:
  SkeletonBuilder();
  ~SkeletonBuilder();
  virtual void buildType();
};

