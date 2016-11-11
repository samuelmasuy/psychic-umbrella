/**
 * @file ChestBuilder.cpp
 * @brief Implementation of chest builder
 */
#include "ChestBuilder.h"

ChestBuilder::ChestBuilder() {
}

void ChestBuilder::buildItem(){
	ItemBuilder* randomItemBuilder = new RandomBuilder();
	randomItemBuilder->createNewItem();
	randomItemBuilder->buildType();
	randomItemBuilder->buildEnhancement();
	chest->setChestContent(randomItemBuilder->getItem());
}

ChestBuilder::~ChestBuilder() {
}
