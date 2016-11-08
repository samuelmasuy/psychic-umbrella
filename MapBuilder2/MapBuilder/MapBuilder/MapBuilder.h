#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

#define CELL_TYPE char
using namespace std;
class MapObserver;
///
/// Here we are giving Labels based on the cell type
///


#define CHAR_EMPTY   ' '
#define CHAR_PLAYER  'P'
#define CHAR_ENEMY   'E'
#define CHAR_WALL    '*'
#define CHAR_ENTRY	 'I'
#define CHAR_EXIT	 'O'
#define CHAR_CHEST   'c'
#define CHAR_ARMOR   'a'
#define CHAR_SHIELD  's'
#define CHAR_WEAPON  'w'
#define CHAR_BOOTS   'b'
#define CHAR_RING    'r'
#define CHAR_HELMET  'h'



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
	/// Here we set the create map
	///
	bool Create(int rows, int cols);
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
	/// We use this to save a map
	///
	int SaveMap(const char *filename);
	///
	/// Here we can retrieve a cell value
	///
	CELL_TYPE GetCell(int i, int j);
	///
	/// This are our getters
	///
	inline int  GetRows() { return m_rows; }
	inline int  GetCols() { return m_cols; }
	inline void GetPlayerPos(int &r, int &c) { r = m_iPlayer; c = m_jPlayer; }
	inline void GetEntrancePos(int &r, int &c) { r = m_i0; c = m_j0; }
	inline void GetExitPos(int &r, int &c) { r = m_i1; c = m_j1; }

	///
	/// Here we can store a cell into the map. It will notify the change to all observers based on the notify method above
	///
	void StoreCell(int i, int j, CELL_TYPE value);
	///
	/// remove a item into the cell. It will notify the change to all observers!
	///
	void RemoveCell(int i, int j);
	///
	/// return true if the cell position is a valid position into the scene
	///
	bool ValidPos(int i, int j);
	///
	/// Here we set it so it returns true if the cell called is valid
	///
	bool ValidCell(CELL_TYPE x);
	///
	/// Here we will use this to validate the map before saving, or after loading
	///
	int ValidateMap();
	///
	/// Here we return the string associated to a cell
	///
	string CellToString(CELL_TYPE x);
	///
	///Here we find an item on the map, and remove it
	///
	void FindAndRemove(CELL_TYPE x);
	///
	/// Here we retrieve the position of the first occurance of the item. We set it returns true if the item was found
	///
	bool FindItem(CELL_TYPE x, int &row, int &col);
	///
	/// Here we are setting the entrance of the map. Returns true if the position is valid
	/// also returns false if the position is not valid, or contains a wall
	///
	bool SetEntrance(int i, int j);
	///
	/// Here we are setting the exit of the map. Returns true if the position is valid
	/// also returns false if the position is not valid, or contains a wall
	///
	bool SetExit(int i, int j);
	///
	/// Here we are setting the player position on the map. Returns true if the position is valid
	/// also returns false if the position is not valid, or contains a wall
	///
	bool SetPlayerPos(int i, int j);
	

private:
	///
	/// vector of observers
	///
	vector < class MapObserver * > m_views;
	///
	/// the scene itselft (a 2D array)
	///
	CELL_TYPE **m_scene;
	///
	///Setting size of the map
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
	///
	/// Our entrance position
	int m_i0, m_j0;
	///
	/// Our exit position
	///
	int m_i1, m_j1;
	///
	/// Our player position
	///
	int m_iPlayer, m_jPlayer;

};

