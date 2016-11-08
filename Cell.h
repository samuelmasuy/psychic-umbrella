#pragma once

enum CellType {
	FREE,
	WALL,
	CHARACTER,
	OPPONENT,
	CHEST,
	DOOR
};

class Cell
{
public:
	Cell();
	Cell(CellType);
	CellType get_Cell_Type();
	void set_Cell_Type(CellType);
	virtual ~Cell();

protected:

private:
	CellType cell_type;
};


