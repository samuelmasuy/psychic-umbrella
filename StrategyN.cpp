#include "StrategyN.h"

StrategyN::StrategyN()
{
}


StrategyN::~StrategyN()
{
}

bool StrategyN::checkCell(Coord2D* inputCoord, Map* inputMap, char type) {
	vector<Coord2D> outputLocation;
	if (inputMap->GetCell(inputCoord->y, inputCoord->x) == type) {  
		return true;
	}
	else return false;
}

Coord2D* StrategyN::identifyTargetCell(int inputX, int inputY, Map* inputMap, char type){
	vector<Coord2D*> testCoords;
	testCoords.push_back(new Coord2D(inputX + 1, inputY + 1)); 
	testCoords.push_back(new Coord2D(inputX, inputY + 1));
	testCoords.push_back(new Coord2D(inputX -1, inputY + 1));
	testCoords.push_back(new Coord2D(inputX, inputY + 1));
	testCoords.push_back(new Coord2D(inputX, inputY - 1));
	testCoords.push_back(new Coord2D(inputX - 1, inputY + 1));
	testCoords.push_back(new Coord2D(inputX - 1, inputY));
	testCoords.push_back(new Coord2D(inputX - 1, inputY - 1));

	Coord2D* identifiedCoord = nullptr;

	for(int i = 0; i < testCoords.size(); i++){
		if (checkCell(testCoords[i], inputMap, type))
			return new Coord2D(testCoords[i]->x, testCoords[i]->y);
	}

	return identifiedCoord;
}

void StrategyN::move(Coord2D* targetLocation, Map* inputMap, Character* mover, char type){
		char oldCellType = inputMap->GetCell(mover->getPositionY(), mover->getPositionX());
		inputMap->fillCell(mover->getPositionY(), mover->getPositionX(), CHAR_EMPTY);
		inputMap->fillCell(targetLocation->y, targetLocation->x, type); 
		mover->setPositionX(targetLocation->x);
		mover->setPositionY(targetLocation->y);
}

bool StrategyN::combat(Character* fighter, Character* monster){
	int attacksPerRound = fighter->getAttacksPerRound();
	int fighterDamage = fighter->getDamageBonus();
	int monsterDamage = monster->getDamageBonus();
	int result = 0;
	// create a new instance of DiceRoller
	DiceRoller* dice_roller = new DiceRoller();

	try {
		// roll dice with valid query
		result = dice_roller->roll("1d20[+0]");
		if (DiceLogger::isOn()) DiceLogger::fout() << "Dice Rolled: 1d20[+0]" << endl;
		if (DiceLogger::isOn()) DiceLogger::fout() << "Result is:" << result << endl;

		fighterDamage += result;

		cout << endl;
		cout << "  / _ /_  __/_  __/ _ |/ ___/ //_/ /" << endl;
		cout << " / __ |/ /   / / / __ / /__/ ,< /_/ " << endl;
		cout << "/_/ |_/_/   /_/ /_/ |_\\___/_/|_(_)  " << endl << endl;

		for (int i = 1; i < attacksPerRound + 1; i++) {
			cout << "Round " << i << endl;
			if (AttLogger::isOn()) AttLogger::fout() << "Attack On, Round:" << i << endl;
			cout << "You hit the monster for: " << fighterDamage << endl;
			monster->hit(fighterDamage);
			if (AttLogger::isOn()) AttLogger::fout() << "You hit the monster for:" << fighterDamage << endl;
			cout << "Monster hits you for: " << monsterDamage << endl;
			fighter->hit(monsterDamage);
			if (AttLogger::isOn()) AttLogger::fout() << "Monster hits you for:" << monsterDamage << endl;
			system("pause");
		}
		monster->setHitPoints(monster->getHitPoints());

		return true;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return false;
}
