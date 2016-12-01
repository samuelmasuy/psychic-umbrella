#pragma once
#include "MonsterBuilder.h"
class MedusaBuilder :
	public MonsterBuilder
{
public:
	MedusaBuilder();
	~MedusaBuilder();
	virtual void buildType();
};

