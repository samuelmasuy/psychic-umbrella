#include "ChestBuilder.h"



ChestBuilder::ChestBuilder()
{
}

void ChestBuilder::buildItem(){
	ItemBuilder* randomItemBuilder = new RandomBuilder();
	randomItemBuilder->createNewItem();
	chest->setChestContent(randomItemBuilder->getItem());
}

ChestBuilder::~ChestBuilder()
{
}
