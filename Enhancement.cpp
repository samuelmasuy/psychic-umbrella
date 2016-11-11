#include "Enhancement.h"


//default constructor
Enhancement::Enhancement()
{
	type = "";
	bonus = 0;
}


// constructor
Enhancement::Enhancement(string type_name, int bonus_value) 
{
	type = type_name;
	bonus = bonus_value;
}

// getter method that return the type of the Enhancement object
string Enhancement::getType() 
{
	return type;
}

// getter method that return the bonus of the Enhancement object
int Enhancement::getBonus()
{
	return bonus;
}

void Enhancement::setEnhancement(string type_name, int bonus_val)
{
	type = type_name;
	bonus = bonus_val;
}

void Enhancement::setType(string inputType) 
{ 
	type = inputType;
}

void Enhancement::setBonus(int inputBonus)
{
	bonus = inputBonus;
}

Enhancement::~Enhancement()
{
}
