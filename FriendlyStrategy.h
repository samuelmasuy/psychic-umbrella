#pragma once
#include "Strategy.h"
#include "Map.h"

class FriendlyStrategy : public Strategy
{

public:
	FriendlyStrategy();
	~FriendlyStrategy();
	void execute(int, int, bool, int, int, Map);

private:

};