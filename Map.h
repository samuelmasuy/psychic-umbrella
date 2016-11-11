#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

#define CELL_TYPE char
using namespace std;


#define CHAR_EMPTY   ' '
#define CHAR_PLAYER  'P'
#define CHAR_ENEMY   'E'
#define CHAR_WALL    '*'
#define CHAR_ENTRY	 'I'
#define CHAR_EXIT	 'O'
#define CHAR_CHEST   'c'
/* would be added in future releases
#define CHAR_ARMOR   'a'
#define CHAR_SHIELD  's'
#define CHAR_WEAPON  'w'
#define CHAR_BOOTS   'b'
#define CHAR_RING    'r'
#define CHAR_HELMET  'h'
*/

class Map
{
public:
	///
	/// default constructor
	///
	Map();
	///
	/// constructor with size
	///
	Map(int rows, int cols);
	///
	/// copy constructor
	///
	Map(const Map &x);
	///
	/// destructor
	///
	~Map();
	///
	/// overloading
	///
	Map & operator = (const Map &x);
	///
	/// creates a map
	///
	bool Create(int rows, int cols);
	///
	/// set the map attributes. It assumes that player position, exit and entrance have been set
	///
	void SetMap(int rows, int cols, CELL_TYPE **data);
	///
	/// determine if a path exits between (row0, col0) and (row1, col1)
	///
	bool PathExist(int row0, int col0, int row1, int col1);
	///
	/// retrieve a cell value
	///
	CELL_TYPE GetCell(int i, int j);
	///
	/// retrieve the matrix pointer
	///
	CELL_TYPE **GetMatrix() { return m_scene; };
	///
	/// basic getters
	///
	inline int  GetRows() { return m_rows;  }
	inline int  GetCols() { return m_cols;  }
	inline void GetPlayerPos(int &r, int &c) { r = m_iPlayer; c = m_jPlayer;  }
	inline void GetEntrancePos(int &r, int &c) { r = m_i0; c = m_j0; }
	inline void GetExitPos(int &r, int &c) { r = m_i1; c = m_j1; }
	///
	///store a cell into the map. 
	///
	void setCell(int i, int j, CELL_TYPE value);
  
  void fillCell(int i, int j, CELL_TYPE value);
  
  CELL_TYPE retrieveCell(int i, int j);

  void print();
  
  void reinitializeMap();
	///
	/// retrieve a cell value, by ref
	///
	CELL_TYPE &GetCellByRef(int i, int j);
	///
	///remove a cell, leave it empty. 
	///
	void RemoveCell(int i, int j);
	///
	/// return true if the cell position is a valid position into the scene
	///
	bool ValidPos(int i, int j);
	///
	/// setting the entrance of the map. Return true if the position is valid
	/// return false if the position is not valid, or contains a wall///
	///
	bool SetEntrance(int i, int j);
	///
	/// setting the exit of the map. Return true if the position is valid
	/// return false if the position is not valid, or contains a wall
	///
	bool SetExit(int i, int j);
	///
	/// setting the player position on the map. Return true if the position is valid
	/// return false if the position is not valid, or contains a wall
	bool SetPlayerPos(int i, int j);
	///
	/// return true if the cell x is valid
	///
	bool ValidCell(CELL_TYPE x);
	///
	/// validate the map before saving, or after loading
	///
	int ValidateMap();
	///
	/// return the string associated to a cell
	///
	string CellToString(CELL_TYPE x);
	///
	/// find an item on the map, and remove it
	///
	void FindAndRemove(CELL_TYPE x);
	///
	/// Retrieve the position of the first ocurrency of a item. Return true if the item was found
	///
	bool FindItem(CELL_TYPE x, int &row, int &col);
	///
	///display the current map
	///
	void Display();

private:
	///
	///the scene itselft (a 2D array)
	///
	CELL_TYPE **m_scene;
	///
	/// size of the map
	///
	int m_rows, m_cols;
	///
	/// release memory of m_scene
	///
	void FreeMem();
	///
	///release memory of a 2D array pointer
	///
	void FreeMem(CELL_TYPE **x, int rows);
	///
	/// alloc memory for a 2D array
	///
	CELL_TYPE **AllocMem(int rows, int cols);
	///
	///backtracking to find a path between [row0,col0] and [row1,col1]
	///
	bool Backtracking(CELL_TYPE **v, int row0, int col0, int row1, int col1);
	///
	///entrance position
	///
	int m_i0, m_j0;
	///
	/// exit position
	///
	int m_i1, m_j1;
	///
	/// player position
	///
	int m_iPlayer, m_jPlayer;

};

