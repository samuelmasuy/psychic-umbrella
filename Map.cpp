#include "Map.h"
#include "MapObserver.h"

///
/// Here we set the default constructor
///
Map::Map()
{
	m_rows = m_cols = 0;
	m_scene = NULL;
	m_i0 = m_j0 = m_i1 = m_j1 = m_iPlayer = m_jPlayer = -1;
}
///
/// Here we set the constructor with size and scene
///
Map::Map(int rows, int cols)
{
	m_scene = NULL;
	m_rows = m_cols = 0;
	m_i0 = m_j0 = m_i1 = m_j1 = m_iPlayer = m_jPlayer = -1;
	Create(rows, cols);
}
///
/// Here we set the constructor with text file (preset maps)
///
Map::Map(const char *filename)
{
	m_scene = NULL;
	m_rows = m_cols = 0;
	m_i0 = m_j0 = m_i1 = m_j1 = m_iPlayer = m_jPlayer = -1;
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
/// Here we set it so we can create a map
///
bool Map::Create(int rows, int cols)
{
	///
	/// Set so it proceeds  only if the map is valid
	///
	if (rows > 0 && cols > 0)
	{
		///
		/// We first set it to free the mem in case we already have a map
		///
		FreeMem();
		m_scene = AllocMem(rows, cols);
		m_rows = rows;
		m_cols = cols;
		///
		///This is building a default map
		///
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
		Notify();
		return true;
	}
	else
	{
		cout << "Invalid dimensions: " << rows << ", " << cols << endl;
		return false;
	}
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
	return ret;
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
	///
	/// Set so we cannot pass through a wall
	///
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
/// Set to validate the following cell types
///
bool Map::ValidCell(CELL_TYPE x)
{
	return
		x == CHAR_EMPTY ||
		x == CHAR_PLAYER ||
		x == CHAR_ENEMY ||
		x == CHAR_WALL ||
		x == CHAR_ENTRY ||
		x == CHAR_EXIT ||
		x == CHAR_CHEST;
  // ||
		// x == CHAR_ARMOR ||
		// x == CHAR_SHIELD ||
		// x == CHAR_WEAPON ||
		// x == CHAR_BOOTS ||
		// x == CHAR_RING ||
		// x == CHAR_HELMET;
}
///
/// Sets to save map
///
int Map::SaveMap(const char *filename)
{
	FILE *f;
	fopen_s(&f, filename, "wt");
	if (!f)
	{
		cout << "Error opening file " << filename << " for writing" << endl;
		return 1;
	}
	fprintf(f, "%d %d %d %d %d %d %d %d\n", m_rows, m_cols, m_i0, m_j0, m_i1, m_j1, m_iPlayer, m_jPlayer);
	for (int i = 0; i<m_rows; i++)
	{
		for (int j = 0; j<m_cols; j++)
		{
			fprintf(f, "%c", m_scene[i][j]);
		}
		fprintf(f, "\n");
	}
	fclose(f);
	return 0;
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
	///
	/// require entrance pos
	int i0 = -1, j0 = -1;
	///
	/// Require exit position
	///
	int i1 = -1, j1 = -1;
	///
	/// Require player position
	///
	int iPlayer = -1, jPlayer = -1;

	if (myfile.is_open())
	{
		int lineNumber = 0;
		while (getline(myfile, line))
		{
			lineNumber++;
			if (lineNumber == 1)
			{
				if (sscanf_s(line.c_str(), "%d %d %d %d %d %d %d %d\n", &r, &c, &i0, &j0, &i1, &j1, &iPlayer, &jPlayer) != 8)
				{
					cout << "This Map is not valid due to its dimensions." << endl;
					return 2;
				}
				else if (r <= 0 || c <= 0)
				{
					cout << "This Map is not valid, all numbers must be positive." << endl;
					return 2;
				}
				else if (i0 < 0 || i0 >= r || j0 < 0 || j0 >= c)
				{
					cout << "This Map is not valid, the entrance is outside the map" << endl;
					return 2;
				}
				else if (i1 < 0 || i1 >= r || j1 < 0 || j1 >= c)
				{
					cout << "This Map is not valid, the exit position is outside the map" << endl;
					return 2;
				}
				else if (iPlayer < 0 || iPlayer >= r || jPlayer < 0 || jPlayer >= c)
				{
					cout << "This Map is not valid, the player position is outside the map" << endl;
					return 2;
				}
				else
					aux = AllocMem(r, c);
			}
			else if (lineNumber <= r + 1)
			{
				if (line.size() < (unsigned int)c)
				{
					cout << "This Map is invalid due to line #" << lineNumber << "." << c << " characters expected instead of " << line.size() << endl;
					FreeMem(aux, r);
					return 3;
				}
				for (int j = 0; j < c; j++)
				{
					if (!ValidCell(line[j]))
					{
						cout << "This Map is invalid due to Character (" << line[j] << ") at line #" << lineNumber << endl;
						FreeMem(aux, r);
						return 4;
					}
					else
					{
						aux[lineNumber - 2][j] = line[j];
						CELL_TYPE x = line[j];
						if (x == CHAR_PLAYER || x == CHAR_ENTRY || x == CHAR_EXIT)
						{
							cout << "Map is invalid, Player, Entrance, and Exit is already set" << endl;
							FreeMem(aux, r);
							return 4;
						}
					}
				}
			}
		}

		myfile.close();
	}
	else
	{
		cout << "Unable to open file: " << filename << endl;
		return 1;
	}
	///
	/// copy aux into m_scene
	///
	FreeMem();
	m_rows = r;
	m_cols = c;
	m_scene = aux;
	m_iPlayer = iPlayer;
	m_jPlayer = jPlayer;
	m_i0 = i0;
	m_i1 = i1;
	m_j0 = j0;
	m_j1 = j1;

	if (PathExist(i0, j0, i1, j1) == false)
	{
		cout << "The Map is not valid, no path is found between the entrance and exit" << endl;
		FreeMem();
		return 4;
	}

	Notify();
	return 0;
}
///
/// Here we store a cell into the map. It will notify the change to the observer.
///
void Map::StoreCell(int i, int j, CELL_TYPE value)
{
	if (ValidPos(i, j) && ValidCell(value) && value != CHAR_EXIT && value != CHAR_ENTRY && value != CHAR_PLAYER)
	{
		m_scene[i][j] = value;
		Notify();
	}
	else
		cout << "Invalid position or cell type" << endl;
}
///
/// Here we Remove a cell from the map. It will notify the change to the observer.
///
void Map::RemoveCell(int i, int j)
{
	if (ValidPos(i, j))
	{
		m_scene[i][j] = CHAR_EMPTY;
		Notify();
	}
	else
		cout << "Cannot remove a cell on invalid position" << endl;

}
///
/// Here we can retrieve a cell value
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
/// Here we return true if the cell position is a valid position into the scene
///
bool Map::ValidPos(int i, int j)
{
	return i >= 0 && i < m_rows && j >= 0 && j < m_cols;
}

///
/// Here we are setting an entrance into the map, returns false if its a wall or not a valid position
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
	Notify();
	return true;
}

///
/// Here we are setting an exit, returns false if its a wall or not a valid position
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
	Notify();
	return true;
}
///
/// Here we are setting an exit, returns false if its a wall or not a valid position
///
bool Map::SetPlayerPos(int i, int j)
{
	if (!ValidPos(i, j))
		return false;
	if (m_scene[i][j] == CHAR_WALL)
		return false;
	m_iPlayer = i;
	m_jPlayer = j;
	Notify();
	return true;
}

///
/// Validation
///
int Map::ValidateMap()
{
	if (m_rows <= 0 || m_cols <= 0)
	{
		cout << "This is not Valid, Please load a valid map or Make a new one!" << endl;
		return 1;
	}
	if (m_i0 < 0 || m_i0 >= m_rows || m_j0 < 0 || m_j0 >= m_cols)
	{
		cout << "This Map is not valid due to the entry position" << endl;
		return 1;
	}
	if (m_i1 < 0 || m_i1 >= m_rows || m_j1 < 0 || m_j1 >= m_cols)
	{
		cout << "This Map is not valid due to the exit position" << endl;
		return 1;
	}
	if (m_iPlayer < 0 || m_iPlayer >= m_rows || m_jPlayer < 0 || m_jPlayer >= m_cols)
	{
		cout << "This Map is not valid due to the player position" << endl;
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
/// Use this to  find an item on the map, and remove it
void Map::FindAndRemove(CELL_TYPE x)
{
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)
			if (m_scene[i][j] == x)
				m_scene[i][j] = CHAR_EMPTY;
}
///
/// Find the item. Return true if the item was found
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
	case CHAR_ENEMY: return "Enemy"; break;
	case CHAR_WALL: return "Wall"; break;
	case CHAR_ENTRY: return "Entrance"; break;
	case CHAR_EXIT: return "Exit"; break;
	case CHAR_CHEST: return "Chest"; break;
	// case CHAR_ARMOR: return  "Armor"; break;
	// case CHAR_SHIELD: return "Shield"; break;
	// case CHAR_WEAPON: return "Weapon"; break;
	// case CHAR_BOOTS: return "Boots"; break;
	// case CHAR_RING: return "Ring"; break;
	// case CHAR_HELMET: return "Helmet"; break;
	}
	return "Invalid";
}
