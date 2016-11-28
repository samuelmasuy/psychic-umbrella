#ifndef BULLYBUILDER_H
#define BULLYBUILDER_H
#include "CharacterBuilder.h"

class BullyBuilder: public CharacterBuilder {
public:
    BullyBuilder();
    virtual ~BullyBuilder();
    virtual void buildAbilityMods();
    virtual void buildType();
};


#endif /* BULLYBUILDER_H */

