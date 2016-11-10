#include "MapBuilderA.h"
///
/// default constructor
///
MapBuilderA::MapBuilderA() : MapBuilder()
{
}
///
/// destructor
///
MapBuilderA::~MapBuilderA()
{
}
///
/// returns the size of the map
///
void MapBuilderA::GetSize(int &rows, int &cols)
{
	rows = m_rows;
	cols = m_cols;
}
///
/// returns the player position
///
void MapBuilderA::GetPlayerPos(int &i, int &j)
{
	i = m_iPlayer;
	j = m_jPlayer;
}
///
/// returns the entrance position
///
void MapBuilderA::GetEntrancePos(int &i, int &j)
{
	i = m_i0;
	j = m_j0;
}
///
/// returns the exit position
///
void MapBuilderA::GetExitPos(int &i, int &j)
{
	i = m_i1;
	j = m_j1;
}
///
/// Points to 2d array
///
CELL_TYPE **MapBuilderA::Get2DArray()
{
	return m_scene;
}
///
/// Loads Map
///
int MapBuilderA::LoadMap(const char *filename)
{
	string line;
	ifstream myfile(filename);

	if (myfile.is_open())
	{
		int lineNumber = 0;
		while (getline(myfile, line))
		{
			lineNumber++;
			if (lineNumber == 1)
			{
				if (sscanf_s(line.c_str(), "%d %d %d %d %d %d %d %d\n", &m_rows, &m_cols, &m_i0, &m_j0, &m_i1, &m_j1, &m_iPlayer, &m_jPlayer) != 8)
				{
					cout << "Invalid Map: Error loading map dimensions" << endl;
					return 2;
				}
				else if (m_rows <= 0 || m_cols <= 0)
				{
					cout << "Inmvalid Map: Rows and Columns should be positive!" << endl;
					return 2;
				}
				else if (m_i0 < 0 || m_i0 >= m_rows || m_j0 < 0 || m_j0 >= m_cols)
				{
					cout << "Invalid Map: entry position is outside the map" << endl;
					return 2;
				}
				else if (m_i1 < 0 || m_i1 >= m_rows || m_j1 < 0 || m_j1 >= m_cols)
				{
					cout << "Invalid Map: exit position is outside the map" << endl;
					return 2;
				}
				else if (m_iPlayer < 0 || m_iPlayer >= m_rows || m_jPlayer < 0 || m_jPlayer >= m_cols)
				{
					cout << "Invalid Map: player position is outside the map" << endl;
					return 2;
				}
				else
					m_scene = AllocMem(m_rows, m_cols);
			}
			else if (lineNumber <= m_rows + 1)
			{
				// read one line
				if (line.size() < (unsigned int)m_cols)
				{
					cout << "Invalid Map: Invalid line #" << lineNumber << "." << m_cols << " characters expected instead of " << line.size() << endl;
					FreeMem();
					return 3;
				}
				for (int j = 0; j < m_cols; j++)
				{
					CELL_TYPE x = line[j];
					if (x != CHAR_EMPTY && x != CHAR_WALL && x != CHAR_CHEST && x != CHAR_ENEMY)	// validating the cell
					{
						if (x == CHAR_PLAYER || x == CHAR_ENTRY || x == CHAR_EXIT)
						{
							cout << "Invalid map: player, entrance and exit should not be specified again in the map" << endl;
							FreeMem();
							return 4;
						}
						else
							cout << "Invalid Map: Character (" << x << ") at line #" << lineNumber << endl;
						FreeMem();
						return 4;
					}
					else
						m_scene[lineNumber - 2][j] = x;
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

	return 0;
}
