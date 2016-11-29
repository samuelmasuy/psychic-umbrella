#ifndef ITEMCONTAINER_H
#define ITEMCONTAINER_H

#include <string>
#include <vector>
#include "Item.h"
using namespace std;

/**
 * @brief Item container, for example a chest
 */
class ItemContainer {
public:
	ItemContainer();
	ItemContainer(vector<Item> items);
	//~ItemContainer();
	vector<Item> getItems();
	void addItem(Item item);
	Item getItem(string itemType);
	string getItemTypeAtIndex(int);
	bool validateItemsInContainer();
	Item getItemAtIndex(int);
	//added
	int getSize();
	void removeItem(int);
	void removeItem(string);
	int getItemIndex(string);
	void printBackpack();

private:
	vector<Item> items;
	int size;
};

#endif
