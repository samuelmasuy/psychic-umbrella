#include "Chest.h"


Chest::Chest(){
	positionX = 0;
	positionY = 0;
}

Chest::Chest(int inputPositionX, int inputPositionY, Item* inputChestContent){
	positionX = inputPositionX;
	positionY = inputPositionY;
	chestContent = inputChestContent;
}

void Chest::setPositionX(int inputPositionX){
	positionX = inputPositionX;
}

int Chest::getPositionX(){
	return positionX;
}

void Chest::setPositionY(int inputPositionY){
	positionY = inputPositionY;
}

int Chest::getPositionY(){
	return positionY;
}

void Chest::setChestContent(Item* inputItem){
	chestContent = inputItem;
}

Item* Chest::getItem(){
	return chestContent;
}


Chest::~Chest()
{
}
