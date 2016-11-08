#include <iostream>
#include "Character.h"
#include "Cell.h"
#include "Enhancement.h"
#include "ItemContainer.h"
#include "Item.h"
#include "Map.h"
#include "MapObserver.h"
#include "Subject.h"
#include "Observer.h"
#include "CharacterOBS.h"



using namespace std;

void main()
{
	cout << "it builds";
	system("pause");
	Character*  character = new Character();
	Item newItem;
	Map* map = new Map();

	character->playerInfo();
	map->print_map();
	system("pause");
}