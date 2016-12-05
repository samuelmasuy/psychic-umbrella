#pragma once

#include "MapBuilder.h"


class MapDirector {
 public:
  ///
  /// default constructor
  ///
  MapDirector();
  ///
  /// destructor
  ///
  virtual ~MapDirector();
  ///
  /// set builder to mapbuilder
  ///
  void SetBuilder(MapBuilder *p);

  void GetMap(Map &m);
  ///
  /// Returns pointer to the Map
  ///
  Map *GetMapPtr();


 private:

  MapBuilder *m_pBuilder;
};

