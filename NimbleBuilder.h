#ifndef NIMBLEBUILDER_H_
#define NIMBLEBUILDER_H_
#include "CharacterBuilder.h"

class NimbleBuilder: public CharacterBuilder {
public:
    NimbleBuilder();
    virtual ~NimbleBuilder();
    virtual void buildAbilityMods();
    virtual void buildType();
};

#endif /* NIMBLEBUILDER_H_ */
