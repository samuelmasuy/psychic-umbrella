/*
 * Fighter.h
 *
 *  Created on: Nov 21, 2016
 *      Author: ahmad
 */

#ifndef FIGHTER_H_
#define FIGHTER_H_
#include "CharacterBuilder.h"
#include <iostream>

using namespace std;

namespace std {

class Fighter {
public:
    Fighter(){

    }
    ~Fighter(){

    }
	void setCharacterBuilder(CharacterBuilder* chBldr){

		myCharBuilder = chBldr;
	}

	Character* getCharacter(){
		return myCharBuilder->getCharacter();
	}
	void constructCharacter(){

            myCharBuilder->createNewCharacter();
            myCharBuilder->buildAbilityMods();
            myCharBuilder->buildType();
	}


private:
	CharacterBuilder* myCharBuilder;
};

} /* namespace std */

#endif /* FIGHTER_H_ */
