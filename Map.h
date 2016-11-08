#pragma once

#include <utility>
#include <vector>
#include <list>
#include "Cell.h"
#include "Subject.h"

using namespace std;

class Map : public Subject
{
public:
	Map();
	Map(int, int);
	int get_map_height();
	int get_map_width();
	pair<int, int> get_beginning_cell();
	pair<int, int> get_end_cell();
	void set_beginning_cell(int, int);
	void set_end_cell(int, int);
	void print_map();
	void set_cell_type(CellType, int, int);
	virtual ~Map();

protected:

private:
	int map_height;
	int map_width;
	vector< vector<Cell>> map_grid;
	pair <int, int> beginning_cell;
	pair <int, int> end_cell;
	
};



