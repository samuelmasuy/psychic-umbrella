#pragma once
#include "ChestBuilder.h"

class ChestDirector
{
public:
	ChestDirector();
	~ChestDirector();
	void setChestBuilder(ChestBuilder* inputChestBuilder) { chestBuilder = inputChestBuilder; };
	Chest* getChest() { return chestBuilder->getChest(); };
	void makeChest() { chestBuilder->createNewChest();};
	

	
private:
	ChestBuilder* chestBuilder;

};

