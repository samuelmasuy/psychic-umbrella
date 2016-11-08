#include "ItemContainer.h"



ItemContainer::ItemContainer()
{
	items = vector<Item>();
	size = 0;
}


ItemContainer::ItemContainer(vector<Item> itemConatiner)
{
	items = itemConatiner;
}

vector<Item> ItemContainer::getItems()
{
	return items;
}


void ItemContainer::addItem(Item item)
{
	items.push_back(item);
	size++;
}

Item ItemContainer::getItem(string itemType)
{
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i].getType() == itemType)
			return items[i];
	}
}


bool ItemContainer::validateItemsInContainer()
{
	for (int i = 0; i < items.size(); i++)
	{
		if (!items[i].validateItem())
		{
			return false;
		}

	}
	return true;
}

//added
int ItemContainer::getSize(){
	return size;
}

int ItemContainer::getItemIndex(string itemType){
	for (int i = 0; i < items.size(); i++)
	if (items[i].getType() == itemType)
		return i;
}

void ItemContainer::removeItem(string itemType){

	int index = getItemIndex(itemType);
	items.erase(items.begin() + index);
}
