/*
 * TankBuilder.h
 *
 *  Created on: Nov 21, 2016
 *      Author: ahmad
 */

#ifndef TANKBUILDER_H
#define TANKBUILDER_H
#include "CharacterBuilder.h"
namespace std {
class TankBuilder: public CharacterBuilder {
public:
    TankBuilder();
    virtual ~TankBuilder();
    virtual void buildAbilityMods();
    virtual void buildType();
};
}

#endif /* TANKBUILDER_H */

