#include "Map.h"

#include <iostream>

	using namespace std;
	//Destructor for Map Class
	Map::~Map(){
	}

	//Default constructor for Map Class, creates a 2 X 2 map using a 2D Vector
	//Beginning cell and End cell set by default to (0,0) and (1,1) respectively
	Map::Map(){
		map_height = 2;
		map_width = 2;

		for (int i = 0; i < map_width; i++)
		{
			map_grid.push_back(vector<Cell>());
			for (int j = 0; j < map_height; j++)
			{
				map_grid[i].push_back(Cell());
			}
		}

		beginning_cell = make_pair(0, 0);
		end_cell = make_pair(1, 1);

	}

	//Parameterized constructor for Map Class, creates a map based on input size using a 2D Vector
	//Beginning cell set to (0,0) and (width-1,height-1) respectively
	Map::Map(int input_map_height, int input_map_width){
		if (input_map_height > 0){
			map_height = input_map_height;
		}
		if (input_map_width > 0){
			map_width = input_map_width;
		}

		for (int i = 0; i < map_width; i++)
		{
			map_grid.push_back(vector<Cell>());
			for (int j = 0; j < map_height; j++)
			{
				map_grid[i].push_back(Cell());
			}
		}
		beginning_cell = make_pair(0, 0);
		end_cell = make_pair(map_width - 1 , map_height - 1);

	}

	//Method to place entities(characters, walls, opponents) on map
	void Map::set_cell_type(CellType input_cell_type, int cell_x, int cell_y){
		map_grid[cell_x][cell_y].set_Cell_Type(input_cell_type);
		notify();
	}

	//Accessor method for map height
	int Map::get_map_height(){
		return map_height;
	}

	int Map::get_map_width(){
		return map_width;
	}

	//Accessor method for beginning cell of map
	pair<int, int> Map::get_beginning_cell(){
		return beginning_cell;
	}

	//Accessor method for ending cell of map
	pair<int, int> Map::get_end_cell(){
		return end_cell;
	}

	//Setter method for beginning cell of map
	void Map::set_beginning_cell(int input_x, int input_y){
		if (input_x >= 0 && input_y >= 0){
			beginning_cell = make_pair(input_x, input_y);
		}
	}

	//Setter method for ending cell of map
	void Map::set_end_cell(int input_x, int input_y){
		if (input_x >= 0 && input_x >= 0){
			end_cell = make_pair(input_x, input_y);
		}
	}

	//Method to print map
	void Map::print_map(){
		for (int i = 0; i < map_height; i++){
			cout << endl;
			for (int j = 0; j < map_width; j++)
			{
				CellType c_t = map_grid[j][i].get_Cell_Type();
				switch (c_t) {
				case FREE:
					cout << "F";
					break;
				case WALL:
					cout << "W";
					break;
				case CHARACTER:
					cout << "C";
					break;
				case OPPONENT:
					cout << "O";
					break;
				case CHEST:
					cout << "c";
					break;
				case DOOR:
					cout << "D";
					break;

				}

			}
		}

	}
