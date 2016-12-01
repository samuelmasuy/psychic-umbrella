#include "Map.h"


///
///default constructor
///
Map::Map()
{
	m_rows = m_cols = 0;
	m_scene = NULL;
	m_i0 = m_j0 = m_i1 = m_j1 = m_iPlayer = m_jPlayer = -1;
	for (int i = 0; i < 6; i++)
		m_enemiesPosition[i].x = m_enemiesPosition[i].y = -1;

	notify(); //notifies map observer
}
///
/// constructor with size
///
Map::Map(int rows, int cols)
{
	m_scene = NULL;
	m_rows = m_cols = 0;
	m_i0 = m_j0 = m_i1 = m_j1 = m_iPlayer = m_jPlayer = -1;
	Create(rows, cols);
	notify(); //notifies map observer
}
///
/// copy constructor 
///
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
		memcpy(m_scene[i], x.m_scene[i], m_cols * sizeof(CELL_TYPE));
	memcpy(m_enemiesPosition, x.m_enemiesPosition, sizeof(Coord2D) * 6);
	notify(); //notifies map observer
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
	memcpy(m_enemiesPosition, x.m_enemiesPosition, sizeof(Coord2D) * 6);
	notify(); //notifies map observer
	return *this;
}

///
/// destructor
///
Map::~Map()
{
	FreeMem();
}
///
///creates a map
///
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
		for (int i = 0; i < 6; i++)
			m_enemiesPosition[i].x = m_enemiesPosition[i].y = -1;
		notify(); //notifies map observer
		return true;
	}
	else
	{
		cout << "Invalid dimensions: " << rows << ", " << cols << endl;
		return false;
	}
}

///
/// determine if a path exits between (row0, col0) and (row1, col1)
///
bool Map::PathExist(int row0, int col0, int row1, int col1)
{
	CELL_TYPE **visited = AllocMem(m_rows, m_cols);

	// all cell are "unvisited"  in this moment
	bool ret = Backtracking(visited, row0, col0, row1, col1);
	FreeMem(visited, m_rows);
	return ret;
}
///
/// backtracking to find a path between [row0,col0] and [row1,col1]
///
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
///
///release memory of a 2D array pointer
///
void Map::FreeMem(CELL_TYPE **x, int rows)
{
	if (x && rows>0)
	{
		//for (int i = 0; i < rows; i++)
		//delete[] x[i];
		//delete[] x;
	}
}
///
/// release memory
///
void Map::FreeMem()
{
	FreeMem(m_scene, m_rows);
	m_scene = NULL;
	m_rows = m_cols = 0;
}
///
/// alloc memory for a 2D array
///
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
		x == CHAR_ELF ||
		x == CHAR_GOBLIN ||
		x == CHAR_LIZARD||
		x == CHAR_MEDUSA||
		x == CHAR_SKELETON ||
		x == CHAR_VINE||
		x == CHAR_WALL ||
		x == CHAR_ENTRY ||
		x == CHAR_EXIT ||
		x == CHAR_FRIENDLY ||
		x == CHAR_DOOR ||
		x == CHAR_CHEST;/* 
						||
						x == CHAR_ARMOR ||
						x == CHAR_SHIELD ||
						x == CHAR_WEAPON ||
						x == CHAR_BOOTS ||
						x == CHAR_RING ||
						x == CHAR_HELMET;*/
}
///
/// store a cell into the map. 
///
void Map::setCell(int i, int j, CELL_TYPE value)
{
	if (ValidPos(i, j) && ValidCell(value) && value != CHAR_EXIT && value != CHAR_ENTRY && value != CHAR_PLAYER)
	{
		m_scene[i][j] = value;
		notify(); //notifies map observer
	}
	else
		cout << "Invalid position or cell type" << endl;
}

/**
* @brief fill a cell into the map.
*
* @param i column
* @param j row
* @param value type to be set
*/
void Map::fillCell(int i, int j, CELL_TYPE value) {
	m_scene[i][j] = value;
	notify(); //notifies map observer
}
void Map::mapInfo()
{
}
/**
* @brief Retrieve a cell from the map
*
* @param i column
* @param j row
*
* @return  a cell type
*/
CELL_TYPE Map::retrieveCell(int i, int j) {
	return m_scene[i][j];
}

CELL_TYPE &Map::GetCellByRef(int i, int j)
{
	if (ValidPos(i, j))
	{
		return m_scene[i][j];
	}
	cout << "Invalid position " << i << "," << j << endl;
	return m_scene[0][0];
}

void Map::RemoveCell(int i, int j)
{
	if (ValidPos(i, j))
	{
		m_scene[i][j] = CHAR_EMPTY;
		notify(); //notifies map observer
	}
	else
		cout << "Cannot remove a cell on invalid position" << endl;
}
///
/// retrieve a cell value
///
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
///
/// return true if the cell position is a valid position into the scene
///
bool Map::ValidPos(int i, int j)
{
	return i >= 0 && i < m_rows && j >= 0 && j < m_cols;
}
///
/// setting the entrance of the map. Return true if the position is valid
/// return false if the position is not valid, or contains a wall
///
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
	notify(); //notifies map observer
	return true;
}
///
///setting the exit of the map. Return true if the position is valid
///return false if the position is not valid, or contains a wall
///
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
	notify(); //notifies map observer
	return true;
}

bool Map::SetPlayerPos(int i, int j)
{
	if (!ValidPos(i, j))
		return false;
	if (m_scene[i][j] == CHAR_WALL)
		return false;
	//m_scene[i][j] = CHAR_PLAYER;  
	m_iPlayer = i;
	m_jPlayer = j;
	notify(); //notifies map observer
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
///
/// find an item on the map, and remove it all occurencies
///
void Map::FindAndRemove(CELL_TYPE x)
{
	bool updated = false;
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)
			if (m_scene[i][j] == x)
			{
				m_scene[i][j] = CHAR_EMPTY;
				updated = true;
			}
	if (updated)
		notify(); //notifies map observer
}
///
/// Retrieve the position of the first ocurrency of a item. Return true if the item was found
///
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
	case CHAR_ELF: return "Elf"; break;
	case CHAR_VINE: return "Vine"; break;
	case CHAR_LIZARD: return "Lizard"; break;
	case CHAR_SKELETON: return "Skeleton"; break;
	case CHAR_MEDUSA: return "Medusa"; break;
	case CHAR_GOBLIN: return "Goblin"; break;
	case CHAR_WALL: return "Wall"; break;
	case CHAR_ENTRY: return "Entrance"; break;
	case CHAR_EXIT: return "Exit"; break;
	case CHAR_CHEST: return "Chest"; break;
	case CHAR_FRIENDLY: return "NPC"; break;
	case CHAR_DOOR: return "Door"; break;
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
	for (int i = 0; i < rows; i++)
	{
		memcpy(m_scene[i], data[i], sizeof(CELL_TYPE) * cols);
		for (int j = 0; j < cols; j++)
		{
			if (m_scene[i][j] >= CHAR_ELF && m_scene[i][j] <= CHAR_MEDUSA)
			{
				m_enemiesPosition[m_scene[i][j] - '1'].x = j;
				m_enemiesPosition[m_scene[i][j] - '1'].y = i;
			}
		}
	}
	notify(); //notifies map observer
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

/**
* @brief Reinitialize to a view neeeded for the main game.
*/
void Map::reinitializeMap() {
	int i0, j0, i1, j1;
	GetEntrancePos(i0, j0);
	GetExitPos(i1, j1);

	for (int r = 0; r < GetRows(); r++) {
		for (int c = 0; c < GetCols(); c++) {
			if (r == i0 && c == j0)
			{
				m_scene[r][c] = CHAR_PLAYER;
				SetPlayerPos(r, c);
			}
			else if (r == i1 && c == j1)
				m_scene[r][c] = CHAR_EXIT;
		}
	}
	notify(); //notifies map observer
}

/**
* @brief Print the map, we always remember the entry postion.
*/
void Map::print() {
	int i0, j0;

	GetEntrancePos(i0, j0);

	m_scene[i0][j0] = CHAR_ENTRY;

	cout << endl;
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			cout << m_scene[i][j];
		}
		cout << endl;
	}
}
int Map::getEntranceRow()
{
	return m_i0;
}
int Map::getEntranceColumn()
{
	return m_j0;
}

int Map::countMonsters()
{
	int count = 0;
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)
			if (m_scene[i][j] >= CHAR_ELF && m_scene[i][j] <= CHAR_MEDUSA)	// here, we count the number of enemies...
				count++;
	return count;

}

bool Map::SetEnemyPos(char enemyType, int i, int j)
{
	if (!ValidPos(i, j))
		return false;
	if (m_enemiesPosition[enemyType - '1'].x != -1)	// because, that enemy was in another pos...
		m_scene[i][j] = CHAR_WALL;
	m_scene[i][j] = enemyType;
	m_enemiesPosition[enemyType - '1'].x = j;
	m_enemiesPosition[enemyType - '1'].y = i;
	return true;
}

bool Map::GetEnemyPos(char enemyType, int &i, int &j)
{
	if (m_enemiesPosition[enemyType - '1'].x == -1)
		return false;
	i = m_enemiesPosition[enemyType - '1'].y;
	j = m_enemiesPosition[enemyType - '1'].x;
}

bool Map::KillEnemy(char enemyType)
{ 
	if (m_enemiesPosition[enemyType - '1'].x != -1)
		m_scene[m_enemiesPosition[enemyType - '1'].y][m_enemiesPosition[enemyType - '1'].x] = CHAR_WALL;
	else
		return false;
	m_enemiesPosition[enemyType - '1'].x = m_enemiesPosition[enemyType - '1'].y = -1;
	return true;
}
