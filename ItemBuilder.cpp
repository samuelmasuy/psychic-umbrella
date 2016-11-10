#include "ItemBuilder.h"


ItemBuilder::ItemBuilder(){
}


ItemBuilder::~ItemBuilder(){
}

void RandomBuilder::buildType(){
      srand(time(NULL));
			int i = rand() % 7;
			switch (i) {
				case 0:
					item->setType("helmet");
					break;
				case 1:
					item->setType("armor");
					break;
				case 2:
					item->setType("shield");
					break;
				case 3:
					item->setType("ring");
					break;
				case 4:
					item->setType("belt");
					break;
				case 5:
					item->setType("boot");
					break;
				case 6:
					item->setType("weapon");
					break;
			}

		}

