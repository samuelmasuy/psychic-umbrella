#ifndef DICETEST_H
#define DICETEST_H

#include <string>

using std::string;

class Dice
{
public:

	//default constructor, initializes the random number generator
	Dice();

	//rolls x dy dice, adds up the values and optionally adds z to it, returns the result
	//regEx: regular expression in the format xdy[+z]
	//returns -1 if the regular expression wasn't in the correct format
	static int roll(const string & Expr);

private:

	//This indicates the number of different kinds of dice we have
	static const int DICEKIND = 7;

	//contains the y value for each dy dice
	static const int DICENUM[DICEKIND];

	//parses the regular expression
	//Expr: expression provided in the format xdy[+z]
	//diceCount: the x value gets saved here
	//diceType: the y value gets saved here
	//addition: the z value gets saved here if it is specified, otherwise it is set to 0
	//returns true if the regular expression was in the correct format, false otherwise
	static bool parse(const string & Expr, int & diceNumber, int & diceKind, int & addition);
};

#endif