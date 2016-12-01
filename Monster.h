/*
 * Monster.h
 *
 *  Created on: Nov 30, 2016
 *      Author: ahmad
 */

#ifndef MONSTER_H_
#define MONSTER_H_
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
	void setPositionX(int);
	void setPositionY(int);
	void setMonsterDamage();
	int getMonsterDamage();

private:
	int currentHitPoints;
	int positionX;
	int positionY;
	int level;
	int damage;
	string monsterType;

};

} /* namespace std */

#endif /* MONSTER_H_ */
