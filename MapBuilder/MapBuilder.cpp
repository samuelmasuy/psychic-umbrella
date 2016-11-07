//! @file
//! @brief Implementation file for the MapBuilder Concrete Class
//!
#include "MapBuilder.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

//! The interactive map builder, reads a map from the file, and fill up the map.
//! @param filename: a valid filepath to the map file.
//! @param level: the level of the map, it should stay to 0!
void FileMapBuilder::buildMap(string filename, int level) {
  ifstream file_reader;
  file_reader.open(filename);

  if( !file_reader )
    cerr << "Cant open " << filename << endl;

  int rows, columns;
  string name;
  char type;
  char newline;

  file_reader >> name >> rows >> columns;
  map = new Map(name, rows, columns);

  for (int i = 0; i < rows; i++) {
    file_reader.get(newline); // get new line
    for (int j = 0; j < columns; j++) {
      file_reader.get(type);
      map->fillCell(type, i, j);
    }

  }

  file_reader.close();
}

//! The interactive map builder, adapts the map to a certain level. It adds chest and enemies on the map.
//! @param filename: a valid filepath to the map file.
//! @param level: the level of the map.
void InteractiveMapBuilder::buildMap(string filename, int level) {
  srand(time(NULL));

  ifstream file_reader;
  file_reader.open(filename);

  if( !file_reader )
    cerr << "Cant open " << filename << endl;

  int rows, columns;
  string name;
  char type;
  char newline;

  file_reader >> name >> rows >> columns;
  map = new Map(name, rows, columns);

  int nbr_enenmy = 0;
  int nbr_chest = 0;
  for (int i = 0; i < rows; i++) {
    file_reader.get(newline); // get new line
    for (int j = 0; j < columns; j++) {
      file_reader.get(type);
      map->fillCell(type, i, j);
      if (type == 'e') {
        nbr_enenmy++;
      } else if (type == 'c') {
        nbr_chest++;
      }
    }

  }
  file_reader.close();

  // fill enemy
  for (int i=0; i<level-nbr_enenmy; ++i) {
    int random_row;
    int random_column;
    do {
      random_row = rand() % map->getRows();
      random_column = rand() % map->getColumns();
    } while (map->getCell(random_row, random_column) != '.');
    map->fillCell('e', random_row, random_column);
  }
  // fill chest
  for (int i=0; i<level-nbr_chest; ++i) {
    int random_row;
    int random_column;
    do {
      random_row = rand() % map->getRows();
      random_column = rand() % map->getColumns();
    } while (map->getCell(random_row, random_column) != '.');
    map->fillCell('c', random_row, random_column);
  }
}
