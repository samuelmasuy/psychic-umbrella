#include "StrategyN.h"

StrategyN::StrategyN()
{
}


StrategyN::~StrategyN()
{
}

bool StrategyN::checkCell(Coord2D* inputCoord, Map* inputMap, char type) {
	vector<Coord2D> outputLocation;
	if (inputMap->GetCell(inputCoord->x, inputCoord->y) == type) {
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
		char oldCellType = inputMap->GetCell(mover->getPositionX(), mover->getPositionY());
		inputMap->fillCell(mover->getPositionX(), mover->getPositionY(), CHAR_EMPTY);
		inputMap->fillCell(targetLocation->x, targetLocation->y, type);
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
		cout << "    Oo    oOoOOoOOo oOoOOoOOo    Oo     .oOOOo. `o    O  " << endl;
		cout << "   o  O       o         o       o  O   .O     o  o   O   " << endl;
		cout << "  O    o      o         o      O    o  o         O  O    " << endl;
		cout << " oOooOoOo     O         O     oOooOoOo o         oOo     " << endl;
		cout << " o      O     o         o     o      O o         o  o    " << endl;
		cout << " O      o     O         O     O      o O         O   O   " << endl;
		cout << " o      O     O         O     o      O `o     .o o    o  " << endl;
		cout << " O.     O     o'        o'    O.     O  `OoooO'  O     O " << endl;
		cout << "                                                         " << endl;
		cout << "                                                         " << endl;

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
