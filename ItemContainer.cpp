#include "ItemContainer.h"



ItemContainer::ItemContainer()
{
	items = vector<Item>();
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
}

Item ItemContainer::getItem(string itemType) 
{
	for (int i = 0; i>items.size(); i++) 
	{
		if (items[i].getType() == itemType) 

			return items[i];
		
	}
}


bool ItemContainer::validateItemContainer() 
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


