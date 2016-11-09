#include "ItemContainer.h"
#include <iostream>



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
	int j = 0;
	for (; j < items.size(); j++)
	{
		if (items[j].getType() == itemType)
		{
			return j;
		}
	}
			
}

void ItemContainer::removeItem(string itemType){

	int index = getItemIndex(itemType);
	items.erase(items.begin() + index);
}

void ItemContainer::printBackpack()
{
	if (items.size() > 0)
	{
		for (int i = 0; i < items.size(); i++)
		{
			cout << items[i].getType() << "{ " << items.at(i).getInfluences().at(0).getType() << " +" << items.at(i).getInfluences().at(0).getBonus() << " }";
		}
	}
	else
		cout << "Backpack is empty\n";
}
