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
	///
	/// return true if the map is valid 
	///
	int ValidateMap();

private:
	///
	/// determine if a path exits between (row0, col0) and (row1, col1)
	///
	bool PathExist(int row0, int col0, int row1, int col1);
	///
	/// backtracking to find a path between [row0,col0] and [row1,col1]
	///
	bool Backtracking(CELL_TYPE **v, int row0, int col0, int row1, int col1);

	///
	/// release memory of a 2D array pointer
	///
	void FreeMem(CELL_TYPE **x, int rows);
	
	Coord2D m_enemiesPositions[6];
};
