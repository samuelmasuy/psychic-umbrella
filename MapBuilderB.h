#pragma once

#include "MapBuilder.h"


class MapBuilderB : public MapBuilder
{
public:
	///
	/// Setting the default constructor
	///
	MapBuilderB();
	///
	/// Setting the destructor
	///
	MapBuilderB(Map &m);
	///
	/// Set to return the size of the map
	///
	virtual ~MapBuilderB();
	///
	///Set to return the Size
	///
	void GetSize(int &rows, int &cols);
	///
	/// Set to  return the Player position
	///
	void GetPlayerPos(int &i, int &j);
	///
	/// Set to return the Entrance position
	///
	void GetEntrancePos(int &i, int &j);
	///
	/// return the exit position
	///
	void GetExitPos(int &i, int &j);
	///
	/// return the array
	///
	CELL_TYPE **Get2DArray();
	///
	/// loads a map from disk
	/// level number >= 0 ... we would add more walls and enemies according to this number
	///
	int LoadMap(const char *filename, int levelNumber);
	///
	/// save the level into file
	///
	int SaveLevel(const char *filename);

};

