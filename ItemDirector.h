#pragma once
#include "ItemBuilder.h"
class ItemDirector
{
public:
	ItemDirector();
	void setItemBuilder(ItemBuilder* inputItemBuilder) { itemBuilder = inputItemBuilder; };
	Item * getItem() { return itemBuilder->getItem; };
	void makeItem();
	~ItemDirector();

private:
	ItemBuilder* itemBuilder;

};

