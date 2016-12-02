/**
 * @file Door.cpp
 * @brief Implementation of the Door
 */
#include "Door.h"

Door::Door() {
  positionX = 0;
  positionY = 0;
}

Door::Door(int inputPositionX, int inputPositionY) {
  positionX = inputPositionX;
  positionY = inputPositionY;
}

void Door::setPositionX(int inputPositionX) {
  positionX = inputPositionX;
}

int Door::getPositionX() {
  return positionX;
}

void Door::setPositionY(int inputPositionY) {
  positionY = inputPositionY;
}

int Door::getPositionY() {
  return positionY;
}


Door::~Door() {
}
