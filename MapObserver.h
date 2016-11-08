#pragma once
#include "Observer.h"
#include "Map.h"
using namespace std;

class MapObserver : public Observer
{
public:
	MapObserver();
	MapObserver(Map*);
	~MapObserver();
	void update();

private:
	Map* observed_map;

};

