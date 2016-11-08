#include "Cell.h"

using namespace std;
//Default constructor Cell
Cell::Cell()
{
	cell_type = FREE;
}
//Parameterized construction for Cell
Cell::Cell(CellType input_cell_type)
{
	cell_type = input_cell_type;
}
//Acessor method for Cell type
CellType Cell::get_Cell_Type()
{
	return cell_type;
}

//Setter method for Cell type
void Cell::set_Cell_Type(CellType input_cell_type)
{
	cell_type = input_cell_type;
}

//Destructor for Cell type
Cell::~Cell()
{
	//dtor
}
