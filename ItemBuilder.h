#pragma once
#include "Item.h"
#include "EnhancementDirector.h"
#include "EnhancementBuilder.h"

#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
//#include <time.h>       /* time */
#include <random>


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
	void buildType() { item->setType("helmet"); };
	void buildEnhancement();
};

class ArmorBuilder : public ItemBuilder {
	void buildType() { item->setType("armor"); }
	void buildEnhancement();
};


class ShieldBuilder : public ItemBuilder{
	void buildType() { item->setType("shield"); }
	void buildEnhancement();
};

class RingBuilder : public ItemBuilder{
	void buildType() { item->setType("ring"); }
	void buildEnhancement();
};

class BeltBuilder : public ItemBuilder{
	void buildType() { item->setType("belt"); }
	void buildEnhancement();
};

class BootBuilder : public ItemBuilder{
	void buildType() { item->setType("boot"); }
	void buildEnhancement();
};

class WeaponBuilder : public ItemBuilder{
	void buildType() { item->setType("weapon"); }
	void buildEnhancement();
};

class RandomBuilder : public ItemBuilder{
	void buildType();
	void buildEnhancement();
};


