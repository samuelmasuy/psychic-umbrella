#ifndef ENHANCEMENT_H
#define ENHANCEMENT_H

#include <string>
#include <vector>


using namespace std;

class Enhancement
{
public:
	Enhancement();
	Enhancement(string type, int bonus);
	string getType();
	int getBonus();
	void setEnhacement(string, int);
	~Enhancement();
	

private:
	string type;
	int bonus;
};

#endif
