/**
 * @file ChestBuilder.cpp
 * @brief Implementation of chest builder
 */
#include "ChestBuilder.h"

ChestBuilder::ChestBuilder() {
}

<<<<<<< HEAD
void ChestBuilder::buildItem(){
	ItemBuilder* randomItemBuilder = new RandomBuilder();
	randomItemBuilder->createNewItem();
	randomItemBuilder->buildType();
	chest->setChestContent(randomItemBuilder->getItem());
=======
void ChestBuilder::buildItem() {
  ItemBuilder* randomItemBuilder = new RandomBuilder();
  randomItemBuilder->createNewItem();
  chest->setChestContent(randomItemBuilder->getItem());
>>>>>>> origin/master
}

ChestBuilder::~ChestBuilder() {
}
