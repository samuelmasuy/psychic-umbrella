#ifndef CHARACTERBUILDER_H_
#define CHARACTERBUILDER_H_
#include "Character.h"


class CharacterBuilder {
public:
	Character* getCharacter(){return myCharacter;}
	void createNewCharacter(){ myCharacter = new Character;}
	virtual void buildAbilityMods() = 0;
  virtual void buildType() = 0;

protected:
	Character* myCharacter;
};


#endif /* CHARACTERBUILDER_H_ */
