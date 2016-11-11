#pragma once

#include <string>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


using namespace std;

class Enhancement
{
public:
	Enhancement();
	Enhancement(string type, int bonus);
	string getType();
	void setType(string inputType) { type = inputType; };
	void setBonus(int inputBonus) { bonus = inputBonus; };
	int getBonus();
	void setEnhancement(string, int);
	~Enhancement();
	

private:
	string type;
	int bonus;
};
