#include "MapObserver.h"
#include "Map.h"

//Default Constructor for MapObserver Class
MapObserver::MapObserver(){
}
//Parameterized Constructor for MapObserver Class, connects Map object to MapObserver
MapObserver::MapObserver(Map* input_observed_Map){
	observed_map = input_observed_Map;
	observed_map->attach(this);
}
//When destroyed detaches itself from map class
MapObserver::~MapObserver(){
	observed_map->detach(this);
}
//Called by Notify, prints Modified Map
void MapObserver::update(){
	observed_map->print_map();
}
