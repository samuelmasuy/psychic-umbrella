#include "Map.h"



// default constructor
Map::Map()
{
	m_rows = m_cols = 0;
	m_scene = NULL;
	m_i0 = m_j0 = m_i1 = m_j1 = m_iPlayer = m_jPlayer = -1;
}

// constructor with size
Map::Map(int rows, int cols)
{
	m_scene = NULL;
	m_rows = m_cols = 0;
	m_i0 = m_j0 = m_i1 = m_j1 = m_iPlayer = m_jPlayer = -1;
	Create(rows, cols);
}

// copy constructor 
Map::Map(const Map &x)
{
	m_i0 = x.m_i0;
	m_j0 = x.m_j0;
	m_i1 = x.m_i1;
	m_j1 = x.m_j1;
	m_iPlayer = x.m_iPlayer;
	m_jPlayer = x.m_jPlayer;
	m_rows = x.m_rows;
	m_cols = x.m_cols;
	m_scene = AllocMem(x.m_rows, x.m_cols);
	for (int i = 0; i < m_rows; i++)
		memcpy(m_scene[i], x.m_scene[i], m_cols * sizeof (CELL_TYPE));
}

Map & Map::operator = (const Map &x)
{
	m_i0 = x.m_i0;
	m_j0 = x.m_j0;
	m_i1 = x.m_i1;
	m_j1 = x.m_j1;
	m_iPlayer = x.m_iPlayer;
	m_jPlayer = x.m_jPlayer;
	m_rows = x.m_rows;
	m_cols = x.m_cols;
	m_scene = AllocMem(x.m_rows, x.m_cols);
	for (int i = 0; i < m_rows; i++)
		memcpy(m_scene[i], x.m_scene[i], m_cols * sizeof(CELL_TYPE));
	return *this;
}


// destructor
Map::~Map()
{
	FreeMem();
}

// creates a map
bool Map::Create(int rows, int cols)
{
	if (rows > 0 && cols > 0)	// proceed  only if the scene is valid
	{
		// first, free mem in case we already have a map
		FreeMem();
		m_scene = AllocMem(rows, cols);
		m_rows = rows;
		m_cols = cols;

		// building a default map
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1)
					m_scene[i][j] = CHAR_WALL;
				else
					m_scene[i][j] = CHAR_EMPTY;
			}
		}
		m_i0 = m_j0 = m_i1 = m_j1 = m_iPlayer = m_jPlayer = -1;
		return true;
	}
	else
	{
		cout << "Invalid dimensions: " << rows << ", " << cols << endl;
		return false;
	}
}


// determine if a path exits between (row0, col0) and (row1, col1)
bool Map::PathExist(int row0, int col0, int row1, int col1)
{
	CELL_TYPE **visited = AllocMem(m_rows, m_cols);

	// all cell are "unvisited"  in this moment
	bool ret = Backtracking(visited, row0, col0, row1, col1);
	FreeMem(visited, m_rows);
	return ret;
}

// backtracking to find a path between [row0,col0] and [row1,col1]
bool Map::Backtracking(CELL_TYPE **v, int row0, int col0, int row1, int col1)
{
	if (!ValidPos(row0, col0))
		return false;
	if (v[row0][col0])	// already visited
		return false;
	// we cannot pass thru a wall
	if (m_scene[row0][col0] == CHAR_WALL)
		return false;
	if (row0 == row1 && col0 == col1)
		return true;
	v[row0][col0] = true;
	bool ret = 
		Backtracking(v, row0 + 1, col0, row1, col1) ||
		Backtracking(v, row0 - 1, col0, row1, col1) ||
		Backtracking(v, row0, col0 + 1, row1, col1) ||
		Backtracking(v, row0, col0 - 1, row1, col1);
	v[row0][col0] = false;
	return ret;
}

// release memory of a 2D array pointer
void Map::FreeMem(CELL_TYPE **x, int rows)
{
	if (x && rows>0)
	{
		for (int i = 0; i < rows; i++)
			delete[] x[i];
		delete[] x;
	}
}

// release memory
void Map::FreeMem()
{
	FreeMem(m_scene, m_rows);
	m_scene = NULL;
	m_rows = m_cols = 0;
}

// alloc memory for a 2D array
CELL_TYPE **Map::AllocMem(int rows, int cols)
{
	CELL_TYPE **aux;
	aux = new CELL_TYPE *[rows];
	for (int i = 0; i < rows; i++)
	{
		aux[i] = new CELL_TYPE[cols];
		memset(aux[i], 0, sizeof(CELL_TYPE)*cols);
	}
	return aux;
}

bool Map::ValidCell(CELL_TYPE x)
{
	return
		x == CHAR_EMPTY ||
		x == CHAR_PLAYER ||
		x == CHAR_ENEMY ||
		x == CHAR_WALL ||
		x == CHAR_ENTRY ||
		x == CHAR_EXIT ||
		x == CHAR_CHEST;/* ||
		x == CHAR_ARMOR ||
		x == CHAR_SHIELD ||
		x == CHAR_WEAPON ||
		x == CHAR_BOOTS ||
		x == CHAR_RING ||
		x == CHAR_HELMET;*/
}

// store a cell into the map. 
void Map::setCell(int i, int j, CELL_TYPE value)
{
	if (ValidPos(i, j) && ValidCell(value) && value != CHAR_EXIT && value != CHAR_ENTRY && value != CHAR_PLAYER)
	{
		m_scene[i][j] = value;
	}
	else
		cout << "Invalid position or cell type" << endl;
}

void Map::RemoveCell(int i, int j)
{
	if (ValidPos(i, j))
		m_scene[i][j] = CHAR_EMPTY;
	else
		cout << "Cannot remove a cell on invalid position" << endl;
}

// retrieve a cell value
CELL_TYPE Map::GetCell(int i, int j)
{
	if (ValidPos(i, j))
	{
		if (m_i0 == i && m_j0 == j)
			return CHAR_ENTRY;
		else if (m_i1 == i && m_j1 == j)
			return CHAR_EXIT;
		else if (m_iPlayer == i && m_jPlayer == j)
			return CHAR_PLAYER;
		else 
			return m_scene[i][j];
	}
	else
		return CHAR_WALL;
}

// return true if the cell position is a valid position into the scene
bool Map::ValidPos(int i, int j)
{
	return i >= 0 && i < m_rows && j >= 0 && j < m_cols;
}

// setting the entrance of the map. Return true if the position is valid
// return false if the position is not valid, or contains a wall
bool Map::SetEntrance(int i, int j)
{
	if (!ValidPos(i, j))
		return false;
	if (m_scene[i][j] == CHAR_WALL)
		return false;
	if (m_scene[i][j] == CHAR_EXIT)
		return false;
	m_i0 = i;
	m_j0 = j;
	return true;
}

// setting the exit of the map. Return true if the position is valid
// return false if the position is not valid, or contains a wall
bool Map::SetExit(int i, int j)
{
	if (!ValidPos(i, j))
		return false;
	if (m_scene[i][j] == CHAR_WALL)
		return false;
	if (m_scene[i][j] == CHAR_ENTRY)
		return false;
	m_i1 = i;
	m_j1 = j;
	return true;
}

bool Map::SetPlayerPos(int i, int j)
{
	if (!ValidPos(i, j))
		return false;
	if (m_scene[i][j] == CHAR_WALL)
		return false;
	m_iPlayer = i;
	m_jPlayer = j;
	return true;
}



int Map::ValidateMap()
{
	if (m_rows <= 0 || m_cols <= 0)
	{
		cout << "Invalid map. It is empty. Please, load a map from disk, or create a new one!" << endl;
		return 1;
	}
	if (m_i0 < 0 || m_i0 >= m_rows || m_j0 < 0 || m_j0 >= m_cols)
	{
		cout << "Invalid map. The entry position has not a valid position" << endl;
		return 1;
	}
	if (m_i1 < 0 || m_i1 >= m_rows || m_j1 < 0 || m_j1 >= m_cols)
	{
		cout << "Invalid map. The exit position has not a valid position" << endl;
		return 1;
	}
	if (m_iPlayer < 0 || m_iPlayer >= m_rows || m_jPlayer < 0 || m_jPlayer >= m_cols)
	{
		cout << "Invalid map. The player position has not a valid position" << endl;
		return 1;
	}

	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			switch (m_scene[i][j])
			{
				case CHAR_ENTRY: 
				case CHAR_EXIT: 
				case CHAR_PLAYER:
					cout << "Entry, exit or player should not be specified in the map; only in the header" << endl;
				return 2;
			}
		}
	}
	if (!PathExist(m_i0, m_j0, m_i1, m_j1))
	{
		cout << "Scene not valid. There is not a path between entrance and exit" << endl;
		return 4;
	}
	return 0;
}

// find an item on the map, and remove it all occurencies
void Map::FindAndRemove(CELL_TYPE x)
{
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)
			if (m_scene[i][j] == x)
				m_scene[i][j] = CHAR_EMPTY;
}

// Retrieve the position of the first ocurrency of a item. Return true if the item was found
bool Map::FindItem(CELL_TYPE x, int &row, int &col)
{
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)
			if (m_scene[i][j] == x)
			{
				row = i;
				col = j;
				return true;
			}
	return false;
}


string Map::CellToString(CELL_TYPE x)
{
	switch (x)
	{
		case CHAR_EMPTY: return "Empty"; break;
		case CHAR_PLAYER: return "Player"; break;
		case CHAR_ENEMY: return "Enemy"; break;
		case CHAR_WALL: return "Wall"; break;
		case CHAR_ENTRY: return "Entrance"; break;
		case CHAR_EXIT: return "Exit"; break;
		case CHAR_CHEST: return "Chest"; break;
			/*
		case CHAR_ARMOR: return  "Armor"; break;
		case CHAR_SHIELD: return "Shield"; break;
		case CHAR_WEAPON: return "Weapon"; break;
		case CHAR_BOOTS: return "Boots"; break;
		case CHAR_RING: return "Ring"; break;
		case CHAR_HELMET: return "Helmet"; break;*/
	}
	return "Invalid";
}

void Map::SetMap(int rows, int cols, CELL_TYPE **data)
{
	FreeMem();
	m_rows = rows;
	m_cols = cols;
	m_scene = AllocMem(rows, cols);
	for (int i = 0; i<rows; i++)
		memcpy(m_scene[i], data[i], sizeof(CELL_TYPE) * rows);
}

void Map::Display()
{
	cout << endl;

	int i0, j0, i1, j1, ip, jp;
	GetPlayerPos(ip, jp);
	GetEntrancePos(i0, j0);
	GetExitPos(i1, j1);

	for (int r = 0; r < GetRows(); r++)
	{
		for (int c = 0; c < GetCols(); c++)
		{
			if (r == ip && c == jp)
				cout << CHAR_PLAYER;
			else if (r == i0 && c == j0)
				cout << CHAR_ENTRY;
			else if (r == i1 && c == j1)
				cout << CHAR_EXIT;
			else
				cout << GetCell(r, c);
		}
		cout << endl;
	}
	cout << endl;
}