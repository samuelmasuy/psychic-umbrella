//! @file
//! @brief Definition file for the MapBuilder abstract Class, and its concrete classes.
//!
#ifndef MapBuilder_h
#define MapBuilder_h

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>


#include "Map.h"


//! Abstract Class implementing  the MapBuilder.
class MapBuilder {

 public:
  Map * getMap() {
    return map;
  }
  virtual void buildMap(string, int = 0) = 0;
 protected:
  Map * map;

};

//! Class implementing  the FileMapBuilder which reads a file and fill up the
//! map.
class FileMapBuilder : public MapBuilder {

 public:
  void buildMap(string, int = 0);
};

//! Class implementing  the InteractiveMapBuilder which reads a file and fill up the
//! map, but also adapts the level of the map by putting more chests and
//! enemies.
class InteractiveMapBuilder : public MapBuilder {

 public:
  void buildMap(string, int);
};

#endif /* MapBuilder_h */
