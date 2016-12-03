/*
 * Monster.h
 *
 *  Created on: Nov 30, 2016
 *      Author: ahmad
 */
#pragma once
#include "Fighter.h"

namespace std {

class Monster: public Fighter {
public:
	Monster();
	Monster(int, int, int, int, int);
	virtual ~Monster();
	void setCharacterType(string type);
	void hit(int);
	void hpChange();
	void levelUp();
	void setLevel(int);
	void setMonsterDamage();
	int getMonsterDamage();

private:
	int currentHitPoints;
	int level;
	int damage;
	string monsterType;

};

} /* namespace std */
