#pragma once
#include "Chest.h"
#include "ItemDirector.h"

class ChestBuilder
{
public:
	ChestBuilder();
	void createNewChest() { chest = new Chest(); buildItem(); };
	Chest* getChest() { return chest; };
	void buildItem();
	~ChestBuilder();

private:
	Chest* chest;
};

