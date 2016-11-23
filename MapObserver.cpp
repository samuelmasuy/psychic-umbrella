#include "MapObserver.h"
#include <iostream>

using namespace std;


MapOBS::MapOBS()
{
}

MapOBS::MapOBS(Map* theMap)
{
	this->theMap = theMap;
	this->theMap->attach(this);
}

void MapOBS::printMapInfo()
{
	system("CLS");
	theMap->mapInfo();
}

void MapOBS::update()
{
	printMapInfo();
}

MapOBS::~MapOBS()
{
	theMap->detach(this);
}

