/*
 * MosnterBuilder.h
 *
 *  Created on: Nov 30, 2016
 *      Author: ahmad
 */

#ifndef MONSTERBUILDER_H_
#define MONSTERBUILDER_H_
#include "Character.h"
#include "Monster.h"

namespace std {

class MonsterBuilder {
public:
	Fighter* getMonster(){return myMonster;}
	void createNewMonster(){ myMonster = new Monster;}
	virtual void buildType() = 0;

protected:
	Fighter* myMonster;
};

} /* namespace std */

#endif /* MOSNTERBUILDER_H_ */
