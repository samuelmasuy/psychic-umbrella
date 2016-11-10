#pragma once

#include "Map.h"
#include "MapBuilderB.h"

class MapEditor
{
public:
	// default constructor
	MapEditor();

	// destructor
	~MapEditor();

	// edit the current map 
	void EditMap(Map *pMap, const string &filename);

private:
	// flush the keyboard buffer
	void Flush();

};
