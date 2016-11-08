#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>


///
///<stdlib.h>: This is a library used for dynamic memory management, in our case the use of freemem, and allocmem
///<iostream>: this will provide our basic input / output streams such as cout / cin and cerr used in the GameEngine and Map.cpp
///<fstream> : This is used for High - level streams of input / output management on our file based systems, used for char, and chartypes
///<string> : This is used to introduce all of our string types
///<vector> : tThis is used for all our vector container classes, such as begin and end etc..
///This project follows d20 rules, an entrance can be set as well as an exit, a path is validated using backtracking and PathExist which checks the path between two sets of rows and columns.
///objects, items, and players can be introduced into the map using the game engine, with the observer being updated as instructed in Assignment 2.
///
#define CELL_TYPE unsigned short
using namespace std;
class MapObserver;
///
/// Here we are giving Labels based on the cell type
///

#define CHAR_EMPTY   ' '
#define CHAR_PLAYER  '0'
#define CHAR_ENEMY   '1'
#define CHAR_WALL    '*'
#define CHAR_ENTRY	 'E'
#define CHAR_EXIT	 'X'
#define CHAR_CHEST   'c'
#define CHAR_ARMOR   'a'
#define CHAR_SHIELD  's'
#define CHAR_WEAPON  'w'
#define CHAR_BOOTS   'b'
#define CHAR_RING    'r'
#define CHAR_HELMET  'h'

enum
	///
	/// Here we are defining all the cell types using enum
	///
{
	CELL_EMPTY = 1,
	CELL_PLAYER = 2,
	CELL_ENEMY = 4,
	CELL_WALL = 8,
	CELL_ENTRY = 16,
	CELL_EXIT = 32,
	CELL_CHEST = 64,
	CELL_ARMOR = 128,
	CELL_SHIELD = 256,
	CELL_WEAPON = 512,
	CELL_BOOTS = 1024,
	CELL_RING = 2048,
	CELL_HELMET = 4096

};


class Map
{
public:
	///
	/// Here is our default constructor
	///
	Map();
	///
	/// Here we set the constructor with size
	///
	Map(int rows, int cols);
	///
	/// Here we set the constructor with a txt file
	///
	Map(const char *filename);
	///
	/// Here we creat a destructor
	///
	~Map();
	///
	/// This is where we attach an observer to the map
	///
	void Attach(MapObserver *obs);
	///
	/// Here we notify a change to all observers if needed
	///
	void Notify();
	///
	/// Here we determine if a path exits between the decided (row0, col0) and (row1, col1)
	///
	bool PathExist(int row0, int col0, int row1, int col1);
	///
	/// Here we can load a map from a txt file given that this is 2d
	///
	int LoadMap(const char *filename);
	///
	/// Here we can retrieve a cell value
	///
	CELL_TYPE GetCell(int i, int j);
	///
	/// This are our getters
	///
	inline int GetRows() { return m_rows; }
	inline int GetCols() { return m_cols; }
	///
	/// Here we can store a cell into the map. It will notify the change to all observers based on the notify method above
	///

	void StoreCell(int i, int j, CELL_TYPE value);

	///
	/// add a item into the cell. It will notify the change to all observers!
	///
	void AddToCell(int i, int j, CELL_TYPE value);

	///
	/// remove a item into the cell. It will notify the change to all observers!
	///

	void RemoveToCell(int i, int j, CELL_TYPE value);

	///
	// return true if the cell position is a valid position into the scene
	///
	bool ValidPos(int i, int j);

	///
	/// setting the entrance of the map. Return true if the position is valid
	/// return false if the position is not valid, or contains a wall
	///
	bool SetEntrance(int i, int j);
	///
	/// setting the exit of the map. Return true if the position is valid
	/// return false if the position is not valid, or contains a wall
	///
	bool SetExit(int i, int j);

private:
	bool m_esceneChanged;

	///
	/// Here we set the vector of observers
	///
	vector < class MapObserver * > m_views;
	///
	/// Here we set the scene itselft (a 2D array)
	///
	CELL_TYPE **m_scene;
	///
	/// Here we set the size of the map
	///
	int m_rows, m_cols;
	///
	/// Here we can release memory of m_scene mentioned previously
	///
	void FreeMem();
	///
	/// Here we can release memory of a 2D array pointer
	///
	void FreeMem(CELL_TYPE **x, int rows);
	///
	/// Here we allocate memory for a 2D array
	///
	CELL_TYPE **AllocMem(int rows, int cols);
	///
	/// Here we are using backtracking to find a path between [row0,col0] and [row1,col1]
	///
	bool Backtracking(CELL_TYPE **v, int row0, int col0, int row1, int col1);
};
