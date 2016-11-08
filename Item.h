#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
#include "Enhancement.h"
using namespace std;

class Item
{
public:
	Item();
	// default constructor
	Item(string type, vector<Enhancement> influence);
	string getType();
	vector<Enhancement> getInfluences();
	bool validateItem();
	/*to do
	void saveItem(Item*);
	void loadItem(Item*);
	*/
	//~Item();

private:
	string type;
	vector<Enhancement> influence;
};



#endif



