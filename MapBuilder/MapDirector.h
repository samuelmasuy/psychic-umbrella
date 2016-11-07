#ifndef MapDirector_h
#define MapDirector_h

#include <iostream>
#include "MapBuilder.h"

//! Class implementing the Map Director for the Builder pattern.
class MapDirector {


 public:
  //! Given a abstract builder, set it on the director
  void setMapBuilder(MapBuilder* mb) {
    mapBuilder = mb;
  }

  //! Get map from MapBuilder once it is ready
  Map * getMap() {
    return mapBuilder->getMap();
  }

  //! Construct the map
  void constructMap(string f, int level = 0) {
    mapBuilder->buildMap(f, level);
  }
 private:
  MapBuilder * mapBuilder;
};

#endif /* MapDirector_h */
