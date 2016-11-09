#pragma once

#include "MapBuilder.h"


class MapBuilderA : public MapBuilder
{
public:
	///
	/// Setting the default constructor
	///
	MapBuilderA();
	///
	/// Setting the destructor
	///
	virtual ~MapBuilderA();
	///
	/// Set to return the size of the map
	///
	void GetSize(int &rows, int &cols);
	///
	///Set to return the player position
	///
	void GetPlayerPos(int &i, int &j);
	///
	/// Set to  return the entrance position
	///
	void GetEntrancePos(int &i, int &j);
	///
	/// Set to return the exit position
	///
	void GetExitPos(int &i, int &j);
	///
	/// return the array
	///
	CELL_TYPE **Get2DArray();
	///
	/// load a map from File
	///
	int LoadMap(const char *filename);


};

