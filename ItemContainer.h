#ifndef ITEMCONTAINER_H
#define ITEMCONTAINER_H

#include <string>
#include <vector>
#include "Item.h"
using namespace std;

class ItemContainer
{
public:
	ItemContainer();
	ItemContainer(vector<Item> items);
	~ItemContainer();
	vector<Item> getItems();
	void addItem(Item item);
	Item getItem(string itemType);
	bool validateItemsInContainer();
private:
	vector<Item> items;
};

#endif

