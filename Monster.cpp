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
	damage = 0;
	level = 1;
}

Monster::Monster(int hp, int posX, int posY, int lvl, int dam){
	currentHitPoints = hp;
	positionX = posX;
	positionY = posY;
	monsterType = "monster";
	level = lvl;
	damage = dam;
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

int Monster::getMonsterDamage(){

	if(level <= 5)
		return 7;
	else if (level <= 10)
		return 14;
	else if (level <= 15)
		return 21;
	else if (level <= 20)
		return 28;
	else
		return 35;
}
void Monster::setMonsterDamage(){

	 damage = getMonsterDamage();
 }

} /* namespace std */



























