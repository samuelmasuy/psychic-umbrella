
#include "Dice.h" 
#include <stdlib.h> 
#include <iostream>
#include <time.h> 

using std::cout;

const int Dice::DICENUM[DICEKIND] = { 4, 6, 8, 10, 12, 20, 100 };
///
///#include "Dice.h" this is included as it is where we created and specificed the Dice Class
///#include "stdlib.h" This Library includes several marcos, functions, and variable types needed, such as the NULL macro, and the rand function
///#include "iosstream" This library includes basic input and output services such as "cout" in this case
///#include "time.h" This library includes the variables and functions used to start the projects random number generator using srand(time)
///
Dice::Dice()
{	
	srand(time(NULL));
	///
	///This starts the random number generator
	///
}


int Dice::roll(const string & Expr) 
{	
	///
	///Below are the variables
	///
	int diceNumber = 0;
	int diceKind = 0;
	int addition = 0;
	int result = 0;
	///
	///parsing the xdy+ z expression provided 
	///
	if (!parse(Expr, diceNumber, diceKind, addition))
	{
		///
		///if it is not in the right format this is the output
		///
		return -1;
	}
	///
	///for each dice
	///
	for (int i = 0; i < diceNumber; i++)
	{
		///	
		///outputs a random number in the range 1-diceKind and add it to the result
		///
		result += (rand() % diceKind) + 1;
	}
	///
	///add the final addition to the result 
	///
	result += addition;

	return result;
}

bool Dice::parse(const string & Expr, int & diceNumber, int & diceKind, int & addition) 
{
	///
	///the variables
	///
	diceNumber = 0;
	diceKind = 0;
	addition = 0;
	///
	///this is the index of the current character in the expression
	///
	int i = 0;
	///
	///this reads the first part of the expression (x) 
	///
	while (i < Expr.size() && Expr[i] >= '0' && Expr[i] <= '9')
	{
		///
		///this updates the value of the number based on the current number
		///
		diceNumber *= 10;
		diceNumber += Expr[i] - '0';
		///
		/// here we tell it to go to the next part of the expression 
		///
		i++;
	}
	///
	///if no number was read, then the expression will not be valid
	///
	if (diceNumber == 0) return false;
	///
	/// here if d is not first then it is not valid
	///
	if (i >= Expr.size() || Expr[i] != 'd') return false;
	///
	/// here we tell it to go to the next part of the expression 
	///
	i++;
	///
	///read the next value in the regular expression (y)
	///
	while (i < Expr.size() && Expr[i] >= '0' && Expr[i] <= '9')
	{
		///
		/// value is updated based on the inputed value
		///
		diceKind *= 10;
		diceKind += Expr[i] - '0';
		///
		/// here we tell it to go to the next expression 
		///
		i++;
	}
	///
	/// here we go through all the different kinds of dice
	///
	for (int d = 0; d < DICEKIND; d++)
	{
		///
		/// if the right kind of dice is inputed then everything will valid
		///
		if (diceKind == DICENUM[d])
		{
			break;
		}
		///
		/// if something is inputed other than the mentioned types then it is not valid and returns -1
		///
		if (d == DICEKIND - 1) return false;
	}


	if (i < Expr.size())
	{

		if (Expr[i] != '+') return false;


		i++;
		///
		/// here we see the third value of the expression which is z
		///
		while (i < Expr.size() && Expr[i] >= '0' && Expr[i] <= '9')
		{
			///
			/// this updates the value based on the inputed number
			///
			addition *= 10;
			addition += Expr[i] - '0';


			i++;
		}

		if (Expr[i - 1] == '+' || i < Expr.size()) return false;
	}
	///
	/// if everything is inputed correctly then it should return the random value
	///
	return true;
}