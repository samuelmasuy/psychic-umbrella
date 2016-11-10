#pragma once
#include "Item.h"
#include "Enhancement.h"
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


using namespace std;

class ItemBuilder
{

public:
	ItemBuilder();
	Item * getItem() { return item; }
	void createNewItem() { item = new Item(); }
	virtual void buildType() = 0;
	virtual void buildEnhancement() = 0;
	~ItemBuilder();

protected:
	Item* item;
};

class HelmetBuilder : public ItemBuilder{
	void buildType() { item->setType("helmet");	}

};

class ArmorBuilder : public ItemBuilder {
	void buildType() { item->setType("armor"); }
};


class SheildBuilder : public ItemBuilder{
	void buildType() { item->setType("shield"); }
};

class RingBuilder : public ItemBuilder{
	void buildType() { item->setType("ring"); }
};

class BeltBuilder : public ItemBuilder{
	void buildType() { item->setType("belt"); }
};

class BootBuilder : public ItemBuilder{
	void buildType() { item->setType("boot"); }
};

class WeaponBuilder : public ItemBuilder{
	void buildType() { item->setType("weapon"); }
};

class RandomBuilder : public ItemBuilder{
	void buildType();
};
