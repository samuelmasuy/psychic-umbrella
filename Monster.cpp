/*
 * Monster.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: ahmad
 */

#include "Monster.h"


namespace std {

Monster::Monster() {
	currentHitPoints = 10;
	positionX = 0;
	positionY = 0;
	monsterType = "monster";
	level = 1;
}

Monster::Monster(int hp, int posX, int posY, int lvl){
	currentHitPoints = hp;
	positionX = posX;
	positionY = posY;
	monsterType = "monster";
	level = lvl;
}

Monster::~Monster() {

}

void Monster::setCharacterType(string type){

	monsterType = type;
}

void Monster::hit(int damage){

	currentHitPoints = currentHitPoints - damage;
}

void Monster::hpChange(){

	currentHitPoints = 10 + (level - 1) * (10 / 2 + 1);
}

void Monster::levelUp(){

	level++;
}

void Monster::setLevel(int lvl){

	level = lvl;
}

void Monster::setPositionX(int x){
	positionX = x;
}

void Monster::setPositionY(int y){
	positionY = y;
}

} /* namespace std */



























