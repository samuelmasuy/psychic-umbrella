#pragma once

#include "map.h"


class MapBuilder
{
public:
	// default constructor
	MapBuilder();

	// destructor
	virtual ~MapBuilder();

	// return the size of the map
	virtual void GetSize(int &rows, int &cols) = 0;

	// return the player position
	virtual void GetPlayerPos(int &i, int &j) = 0;

	// return the entrance position
	virtual void GetEntrancePos(int &i, int &j) = 0;

	// return the exit position
	virtual void GetExitPos(int &i, int &j) = 0;

	// return the array
	virtual CELL_TYPE **Get2DArray() = 0;

protected:

	// size of the map
	int m_rows, m_cols;

	// entrance position
	int m_i0, m_j0;

	// exit position
	int m_i1, m_j1;

	// player position
	int m_iPlayer, m_jPlayer;

	CELL_TYPE **m_scene;

	// release memory of m_scene
	void FreeMem();

	// alloc memory for a 2D array
	CELL_TYPE **AllocMem(int rows, int cols);

};

