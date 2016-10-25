
#ifndef DICE_H
#define DICE_H

#include <stdlib.h> 
#include <iostream>
#include <time.h> 
#include <string>

using std::string;
///
///#include "Dice.h" this is included as it is where we created and specificed the Dice Class
///#include "stdlib.h" This Library includes several marcos, functions, and variable types needed, such as the NULL macro, and the rand function
///#include "iosstream" This library includes basic input and output services such as "cout" in this case
///#include "time.h" This library includes the variables and functions used to start the projects random number generator using srand(time)
///
class Dice
{
public:

	Dice();
	///
	///rolls x dy dice, adds up the values and optionally adds z to it, returns the result
	///Expr: regular expression in the format xdy[+z]
	///returns -1 if the regular expression was not in the correct format
	///
	static int roll(const string & Expr);

private:
	///
	///This indicates the number of different kinds of dice we have
	///
	static const int DICEKIND = 7;
	///
	///contains the y value for each dy dice
	///
	static const int DICENUM[DICEKIND];
	///
	///parses the expression given to us 
	///Expr: expression provided is xdy[+z]
	///diceNumber: the x value gets saved here
	///diceType: the y value gets saved here
	///addition: the z value gets saved here if it is specified, otherwise it is set to 0
	///returns true if the expression was in the correct format, false otherwise
	///
	static bool parse(const string & Expr, int & diceNumber, int & diceKind, int & addition);
};

#endif