//! @file
//! @brief Implementation file for the Map Header file
//!
#include "Map.h"

Map::Map() {
  mapName = "Empty Map 16x16";
  rows = 16;
  columns = 16;

  // Initialize the map grid
  for (int i = 0; i < rows; i++) {
    vector<char> row; // Create an empty row
    for (int j = 0; j < columns; j++) {
      row.push_back('.'); // Add an element (column) to the row
    }
    grid.push_back(row); // Add the row to the main vector
  }
}

Map::Map(string name, int n_columns, int n_rows) {
  mapName = name;
  columns = n_columns;
  rows = n_rows;

  // Initialize the map grid
  for (int i = 0; i < rows; i++) {
    vector<char> row; // Create an empty row
    for (int j = 0; j < columns; j++) {
      row.push_back('.'); // Add an element (column) to the row
    }
    grid.push_back(row); // Add the row to the main vector
  }
}

Map::~Map() {
}

char Map::getCell(int x, int y) {
  return grid[x][y];
}

int Map::getColumns() const {
  return columns;
}

int Map::getRows() const {
  return rows;
}

string Map::getName() const {
  return mapName;
}

void Map::setName(string name) {
  mapName = name;
}

//! Implementation of fill cell, set any cell to anything it might eventually contain
//! @param type: a character value of object that fills the cell
//! @param x: an integer value of horizontal index of the map's grid
//! @param y: an integer value of vertical index of the map's grid
void Map::fillCell(char type, int x, int y) {
  grid[x][y] = type;
}

//! Implementation occupation of a cell, check if a cell is occupied
//! @param x: an integer value of horizontal index of the map's grid
//! @param y: an integer value of vertical index of the map's grid
//! @return : a boolean true if the cell is occupeid false otherwise
bool Map::isOccupied(int x, int y) {
  return grid[x][y] != '.';
}

//! Check Path from a given row and column
//! @param copy: a copy of the map grid
//! @param x: an integer value of horizontal index of the map's grid
//! @param y: an integer value of vertical index of the map's grid
//! @return bool value, true of the map is valid.
bool Map::isValidPath(vector< vector<char> > copy, int x, int y) {
  if (grid[x][y] == 'd') {
    return true;
  } else {
    // set cell as visited.
    copy[x][y] = '+';

    // check right
    if (x + 1 < columns) {
      if (!(copy[x + 1][y] == '+') && !(copy[x + 1][y] == 'w')) {
        if (isValidPath(copy, x + 1, y)) {
          return true;
        }
      }
    }
    // check left
    if (x - 1 >= 0) {
      if (!(grid[x - 1][y] == '+') && !(copy[x - 1][y] == 'w')) {
        if (isValidPath(copy, x - 1, y)) {
          return true;
        }
      }
    }
    // check above
    if (y + 1 < rows) {
      if (!(grid[x][y + 1] == '+') && !(copy[x][y + 1] == 'w')) {
        if (isValidPath(copy, x, y + 1)) {
          return true;
        }
      }
    }
    // check under
    if (y - 1 >= 0) {
      if (!(copy[x][y - 1] == '+') && !(copy[x][y - 1] == 'w')) {
        if (isValidPath(copy, x, y - 1)) {
          return true;
        }
      }
    }
  }
  return false;
}

//! Implementation of the map verification
//! @return bool value, true of the map is valid (there is at least one clear path between the mandatory begin and end cell).
bool Map::validatePath() {
  vector< vector<char> > cp = grid;

  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      if (grid[i][j] == 'd') {
        if (isValidPath(grid, i, j)) {
          return true;
        }
      }
    }
  }
  return false;
}

//! Display the map in the console
void Map::print() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
}
