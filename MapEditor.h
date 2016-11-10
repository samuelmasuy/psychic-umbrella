#pragma once

#include "Map.h"

class MapEditor
{
public:
	// default constructor
	MapEditor();

	// destructor
	~MapEditor();

	// edit the current map 
	void EditMap(Map *pMap);

private:
	// flush the keyboard buffer
	void Flush();

};
