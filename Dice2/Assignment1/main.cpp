#include "Dice.h"
#include <iostream>

using std::cout;
using std::cin;
using std::getline;
using std::string;

int main()
{
	Dice dice;
	string diceNumber, diceKind, addition;
	///
	/// Prompts the question to the user of how many dice they would like to roll
	///
	cout << "How many dice of the same kind would you like to roll?: ";
	getline(cin, diceNumber);
	///
	/// Then prompts the user to pick a kind of dice from the ones presented
	///
	cout << "What is the kind of dice please choose from the following only 4, 6, 8, 10, 12, 20, 100: ";
	getline(cin, diceKind);
	///
	/// Prompts if any additions would like to be added
	///
	cout << "Any additions?: ";
	getline(cin, addition);
	///
	/// provides the result
	///
	int result = dice.roll(diceNumber + "d" + diceKind + "+" + addition);

	cout << result << "\n";

	system("PAUSE");

	return 0;
}