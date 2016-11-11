#pragma once

#include <string>
#include <vector>


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
	void setEnhacement(string, int);
	~Enhancement();
	

private:
	string type;
	int bonus;
};
