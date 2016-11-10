#pragma once
#include "Item.h"

class Chest
{
public:
	Chest();
	Chest(int, int, Item*);
	~Chest();
	void setPositionX(int);
	void setPositionY(int);
	void setChestContent(Item*);
	int getPositionX();
	int getPositionY();
	Item* getItem();

private:
	int positionX;
	int positionY;
	Item* chestContent;
};

