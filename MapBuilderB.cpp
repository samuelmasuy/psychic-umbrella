#include "MapBuilderB.h"
///
/// This is the default constructor
///
MapBuilderB::MapBuilderB() : MapBuilder() {
  for (int i = 0; i < 6; i++) {
    m_enemiesPositions[i].x = m_enemiesPositions[i].y = -1;
  }
}
///
/// We set the building specifications of the map
///
MapBuilderB::MapBuilderB(Map &m) {
  m_rows = m.GetRows();
  m_cols = m.GetCols();
  m.GetEntrancePos(m_i0, m_j0);
  m.GetExitPos(m_i1, m_j1);
  m.GetPlayerPos(m_iPlayer, m_jPlayer);
  m_scene = AllocMem(m_rows, m_cols);
  CELL_TYPE **p = m.GetMatrix();
  for (int r = 0; r < m_rows; r++) {
    memcpy(m_scene[r], p[r], m_cols * sizeof(CELL_TYPE));
    for (int c=0; c< m_cols; c++)
      if (m_scene[r][c] >= CHAR_ELF && m_scene[r][c] <= CHAR_MEDUSA) {
        m_enemiesPositions[r].x = c;
        m_enemiesPositions[r].y = r;
      }
  }
}


///
/// Here is the deconstructor
///
MapBuilderB::~MapBuilderB() {
  //FreeMem();
}
///
/// Set to return the size of the map
///
void MapBuilderB::GetSize(int &rows, int &cols) {
  rows = m_rows;
  cols = m_cols;
}
///
/// Set to return the player position
///
void MapBuilderB::GetPlayerPos(int &i, int &j) {
  i = m_iPlayer;
  j = m_jPlayer;
}
///
/// Set to return the entrance position
///
void MapBuilderB::GetEntrancePos(int &i, int &j) {
  i = m_i0;
  j = m_j0;
}
///
/// Set to return the Exit position
///
void MapBuilderB::GetExitPos(int &i, int &j) {
  i = m_i1;
  j = m_j1;
}
///
/// Pointer
///
CELL_TYPE **MapBuilderB::Get2DArray() {
  return m_scene;
}
///
/// LoadMap from file with the level number
///
int MapBuilderB::LoadMap(const char *filename, int levelNumber) {
  string line;
  ifstream myfile(filename);

  if (myfile.is_open()) {
    int lineNumber = 0;
    while (getline(myfile, line)) {
      lineNumber++;
      if (lineNumber == 1) {
        if (sscanf_s(line.c_str(), "%d %d %d %d %d %d %d %d\n", &m_rows, &m_cols, &m_i0, &m_j0, &m_i1, &m_j1, &m_iPlayer, &m_jPlayer) != 8) {
          cout << "Invalid Map: Error loading map dimensions" << endl;
          return 2;
        } else if (m_rows <= 0 || m_cols <= 0) {
          cout << "Inmvalid Map: Rows and Columns should be positive!" << endl;
          return 2;
        } else if (m_i0 < 0 || m_i0 >= m_rows || m_j0 < 0 || m_j0 >= m_cols) {
          cout << "Invalid Map: entry position is outside the map" << endl;
          return 2;
        } else if (m_i1 < 0 || m_i1 >= m_rows || m_j1 < 0 || m_j1 >= m_cols) {
          cout << "Invalid Map: exit position is outside the map" << endl;
          return 2;
        } else if (m_iPlayer < 0 || m_iPlayer >= m_rows || m_jPlayer < 0 || m_jPlayer >= m_cols) {
          cout << "Invalid Map: player position is outside the map" << endl;
          return 2;
        } else
          m_scene = AllocMem(m_rows, m_cols);
      } else if (lineNumber <= m_rows + 1) {
        if (line.size() < (unsigned int)m_cols) {
          cout << "Invalid Map: Invalid line #" << lineNumber << "." << m_cols << " characters expected instead of " << line.size() << endl;
          //FreeMem();
          return 3;
        }
        for (int j = 0; j < m_cols; j++) {
          if (0) {
            cout << "Invalid Map: Character (" << line[j] << ") at line #" << lineNumber << endl;
            //FreeMem();
            return 4;
          } else {
            m_scene[lineNumber - 2][j] = line[j];
            CELL_TYPE x = line[j];
            if (x == CHAR_PLAYER || x == CHAR_ENTRY || x == CHAR_EXIT) {
              cout << "Invalid map: player, entrance and exit should not be specified again in the map" << endl;
              //FreeMem();
              return 4;
            }
            if (x >= CHAR_ELF && x <= CHAR_MEDUSA) {
              if (m_enemiesPositions[x - '1'].x != -1) {
                cout << "Error, cannot have more than 1 monster of same type in the map" << endl;
                return 5;
              }
              m_enemiesPositions[x - '1'].x = j;
              m_enemiesPositions[x - '1'].y = lineNumber - 2;
            }
            //  i just need to be able to get the position of the enemy
          }
        }
      }
    }

    myfile.close();
  } else {
    cout << "Unable to open file: " << filename << endl;
    return 1;
  }

  for (int k = 0; k < levelNumber * 2; k++) {
    int i = rand() % m_rows;
    int j = rand() & m_cols;
    if ((i != m_i0 || j != m_j0) && (i != m_i1 || j != m_j1) && (i != m_iPlayer || j != m_jPlayer)) {
      // adding a wall or enemy
      if (rand() & 1)
        m_scene[i][j] = NULL;

    }
  }
  return 0;
}

int MapBuilderB::ValidateMap() {
  if (m_rows <= 0 || m_cols <= 0) {
    cout << "Invalid map. It is empty. Please, load a map from disk, or create a new one!" << endl;
    return 1;
  }
  if (m_i0 < 0 || m_i0 >= m_rows || m_j0 < 0 || m_j0 >= m_cols) {
    cout << "Invalid map. The entry position has not a valid position" << endl;
    return 1;
  }
  if (m_i1 < 0 || m_i1 >= m_rows || m_j1 < 0 || m_j1 >= m_cols) {
    cout << "Invalid map. The exit position has not a valid position" << endl;
    return 1;
  }
  if (m_iPlayer < 0 || m_iPlayer >= m_rows || m_jPlayer < 0 || m_jPlayer >= m_cols) {
    cout << "Invalid map. The player position has not a valid position" << endl;
    return 1;
  }

  for (int i = 0; i < m_rows; i++) {
    for (int j = 0; j < m_cols; j++) {
      switch (m_scene[i][j]) {
      case CHAR_ENTRY:
      case CHAR_EXIT:
      case CHAR_PLAYER:
        cout << "Entry, exit or player should not be specified in the map; only in the header" << endl;
        return 2;
        break;

      }
    }
  }
  if (!PathExist(m_i0, m_j0, m_i1, m_j1)) {
    cout << "Scene not valid. There is not a path between entrance and exit" << endl;
    return 4;
  }
  return 0;
}
///
/// determine if a path exits between (row0, col0) and (row1, col1)
///
bool MapBuilderB::PathExist(int row0, int col0, int row1, int col1) {
  CELL_TYPE **visited = AllocMem(m_rows, m_cols);

  bool ret = Backtracking(visited, row0, col0, row1, col1);
  FreeMem(visited, m_rows);
  return ret;
}
///
/// backtracking to find a path between [row0,col0] and [row1,col1]
///
bool MapBuilderB::Backtracking(CELL_TYPE **v, int row0, int col0, int row1, int col1) {
  if (row0<0 || row0 >= m_rows || col0<0 || col0 >= m_cols)
    return false;
  if (v[row0][col0])
    return false;
  ///
  /// we cannot pass thru a wall
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
/// Saving the map here
///
int MapBuilderB::SaveLevel(const char *filename) {
  FILE *f;
  fopen_s(&f, filename, "wt");
  if (!f) {
    cout << "Error opening file " << filename << " for writing" << endl;
    return 1;
  }
  fprintf(f, "%d %d %d %d %d %d %d %d\n", m_rows, m_cols, m_i0, m_j0, m_i1, m_j1, m_iPlayer, m_jPlayer);
  for (int i = 0; i<m_rows; i++) {
    for (int j = 0; j<m_cols; j++) {
      fprintf(f, "%c", m_scene[i][j]);
    }
    fprintf(f, "\n");
  }
  fclose(f);
  return 0;
}
void MapBuilderB::FreeMem(CELL_TYPE **x, int rows) {
  if (x && rows>0) {
    for (int i = 0; i < rows; i++)
      delete[] x[i];
    delete[] x;
  }
}
