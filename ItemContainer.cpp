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
  throw "Item type not found";
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
  return -1;
}

void ItemContainer::removeItem(int index){

	//int index = getItemIndex(itemType);
	items.erase(items.begin() + index);
	size--;

}

void ItemContainer::removeItem(string itemType){

	for (int i = 0; i < items.size(); i++)
	{
		if (items[i].getType() == itemType) {
      items.erase(items.begin() + i);
      size--;
      break;
    }
	}
  throw "Item type not found";
}

void ItemContainer::printBackpack()
{
	if (items.size() > 0)
	{
		cout << "---BACKPACK ITEMS---\n";
		for (int i = 0; i < items.size(); i++)
		{
			cout << i <<". " << items[i].getType() << " {" << items.at(i).getInfluences().at(0).getType() << " +" << items.at(i).getInfluences().at(0).getBonus() << "}" << endl;
		}
	}
	else
		cout << "Backpack is empty\n";
}

string ItemContainer::getItemTypeAtIndex(int index)
{
	string type;
	type = items[index].getType();
	return type;
}

Item ItemContainer::getItemAtIndex(int index)
{

	return items[index];

}
