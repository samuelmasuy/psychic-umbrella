#include "Map.h"
#include "MapObserver.h"
///
/// Here we set the default constructor
///
Map::Map()
{
	m_rows = m_cols = 0;
	m_scene = NULL;
}
///
/// Here we set the constructor with size and scene
///
Map::Map(int rows, int cols)
{
	m_scene = AllocMem(rows, cols);
	m_rows = rows;
	m_cols = cols;
}
///
/// Here we set the constructor with text file (preset maps)
///
Map::Map(const char *filename)
{
	LoadMap(filename);
}
///
/// Here we set the destructor and also releasing the mem
///
Map::~Map()
{
	FreeMem();
}
///
/// Below we attach an observer to the map
///
void Map::Attach(MapObserver *obs)
{
	m_views.push_back(obs);
}
///
/// Any changes are notified to all observers
///
void Map::Notify()
{
	for (unsigned int i = 0; i < m_views.size(); i++)
		m_views[i]->Update();
}
///
/// Here we determine if a path exits between (row0, col0) and (row1, col1)
///
bool Map::PathExist(int row0, int col0, int row1, int col1)
{
	CELL_TYPE **visited = AllocMem(m_rows, m_cols);
	bool ret = Backtracking(visited, row0, col0, row1, col1);
	FreeMem(visited, m_rows);
	return false;
}
///
/// We use backtracking to find a path between [row0,col0] and [row1,col1]
///
bool Map::Backtracking(CELL_TYPE **v, int row0, int col0, int row1, int col1)
{
	if (!ValidPos(row0, col0))
		return false;
	if (v[row0][col0])
		return false;
	if (row0 == row1 && col0 == col1)
		return true;
	v[row0][col0] = true;

	return
		Backtracking(v, row0 + 1, col0, row1, col1) ||
		Backtracking(v, row0 - 1, col0, row1, col1) ||
		Backtracking(v, row0, col0 + 1, row1, col1) ||
		Backtracking(v, row0, col0 - 1, row1, col1);
}
///
/// We release the memory of the 2D array pointer
///
void Map::FreeMem(CELL_TYPE **x, int rows)
{
	if (x && rows>0)
	{
		for (int i = 0; i < rows; i++)
			delete[] x[i];
		delete[] x;
	}
}
///
///All memory is released here
///
void Map::FreeMem()
{
	FreeMem(m_scene, m_rows);
	m_scene = NULL;
	m_rows = m_cols = 0;
}
///
/// Here allocate the memory for a 2D array
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
///
/// Here we set it up so we can load a map from a txt file
///
int Map::LoadMap(const char *filename)
{
	string line;
	ifstream myfile(filename);
	int r = 0, c = 0;
	CELL_TYPE **aux = NULL;
	if (myfile.is_open())
	{
		int lineNumber = 0;
		while (getline(myfile, line))
		{
			lineNumber++;
			if (lineNumber == 1)
			{
				if (sscanf_s(line.c_str(), "%d %d", &r, &c) != 2)
				{
					cout << "Error loading map dimensions" << endl;
					return 2;
				}
				else
					aux = AllocMem(r, c);
			}
			else if (lineNumber <= r + 1)
			{
				// read one line
				if (line.size() < (unsigned int)c)
				{
					cout << "Invalid line #" << lineNumber << endl;
					cout << c << " characters expected" << endl;
					FreeMem(aux, r);
					return 3;
				}
				for (int j = 0; j < c; j++)
				{
					CELL_TYPE x = CELL_EMPTY;
					switch (line[j])
					{
					case CHAR_EMPTY: x = CELL_EMPTY; break;
					case CHAR_WALL:  x = CELL_WALL; break;
					case CHAR_PLAYER:x = CELL_PLAYER; break;
					case CHAR_ENEMY: x = CELL_ENEMY; break;
					case CHAR_CHEST: x = CELL_CHEST; break;
					case CHAR_ARMOR: x = CELL_ARMOR; break;
					case CHAR_SHIELD:x = CELL_SHIELD; break;
					case CHAR_WEAPON:x = CELL_WEAPON; break;
					case CHAR_BOOTS: x = CELL_BOOTS; break;
					case CHAR_RING:  x = CELL_RING; break;
					case CHAR_HELMET:x = CELL_HELMET; break;
					}
					aux[lineNumber - 2][j] = x;
				}
			}
		}
		myfile.close();
	}
	else
	{
		cout << "Unable to open file" << endl;
		return 1;
	}
	///
	/// copy aux into m_scene
	///
	FreeMem();
	m_rows = r;
	m_cols = c;
	m_scene = aux;
	Notify();
	return 0;
}

///
/// Here we store a cell into the map. It will notify the change to the observer.
///
void Map::StoreCell(int i, int j, CELL_TYPE value)
{
	if (ValidPos(i, j))
	{
		m_scene[i][j] = value;
		Notify();
	}
}
///
/// Here we Add a cell into the map. It will notify the change to the observer.
///
void Map::AddToCell(int i, int j, CELL_TYPE value)
{
	if (ValidPos(i, j))
	{
		m_scene[i][j] |= value;
		Notify();
	}
}
///
/// Here we Remove a cell from the map. It will notify the change to the observer.
///
void Map::RemoveToCell(int i, int j, CELL_TYPE value)
{
	if (ValidPos(i, j))
	{
		if (m_scene[i][j] & value)
			m_scene[i][j] -= value;
		Notify();
	}

}
///
/// Here we can retrieve a cell value
///
CELL_TYPE Map::GetCell(int i, int j)
{
	if (ValidPos(i, j))
		return m_scene[i][j];
	else
		return CELL_WALL;
}
///
/// Here we return true if the cell position is a valid position into the scene
///
bool Map::ValidPos(int i, int j)
{
	return i >= 0 && i < m_rows && j >= 0 && j < m_cols;
}

///
/// Here we are setting an enterance into the map 
///
bool Map::SetEntrance(int i, int j)
{
	if (!ValidPos(i, j))
		return false;
	if (m_scene[i][j] & CELL_WALL)
		return false;
	if (m_scene[i][j] & CELL_EXIT)
		return false;
	m_scene[i][j] |= CELL_ENTRY;
	Notify();
	return true;
}
///
/// Here we are setting an exit
///
bool Map::SetExit(int i, int j)
{
	if (!ValidPos(i, j))
		return false;
	if (m_scene[i][j] & CELL_WALL)
		return false;
	if (m_scene[i][j] & CELL_ENTRY)
		return false;
	m_scene[i][j] |= CELL_EXIT;
	Notify();
	return true;
}
