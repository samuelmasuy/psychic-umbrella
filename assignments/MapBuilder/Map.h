//! @file
//! @brief Implementation file for the Map Class
//!
#ifndef MAP_MAP_H
#define MAP_MAP_H

#include "Cell.h"
#include <string>
#include <vector>

//! Class implementing a game map
class Map {
  string mapName;
  int columns, rows;

  vector< vector<char> > grid;

 public:
  Map();
  Map(string, int, int);
  ~Map();

  char getCell(int, int);
  int getColumns() const;
  int getRows() const;
  string getName() const;


  void setName(string);
  void fillCell(char, int, int);

  bool isOccupied(int, int);

  bool isValidPath(vector< vector<char> >, int, int);
  bool validatePath();

  void print();
};

#endif //MAP_MAP_H
