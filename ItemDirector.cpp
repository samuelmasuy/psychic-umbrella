#include "ItemDirector.h"



ItemDirector::ItemDirector()
{
}

void ItemDirector::makeItem(){
	itemBuilder->createNewItem();
	itemBuilder->buildType();
	itemBuilder->buildEnhancement();
	
}


ItemDirector::~ItemDirector()
{
}
