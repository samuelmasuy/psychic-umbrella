#include "GameState.h"

//GameState::GameState()
//{
//
//}

GameState::GameState(Character* inputCharacter, vector<Monster*> inputMonsters, Map* inputMap) {
	mainCharacter = inputCharacter;
	monsters=inputMonsters;
	map = inputMap;
}

void GameState::setMainCharacter(Character* inputMainCharacter){
	mainCharacter = inputMainCharacter;
}

Character* GameState::getMainCharacter(){
	return mainCharacter;

}

void GameState::setMap(Map* inputMap){
	map = inputMap;
}

Map* GameState::getMap(){
	return map;
}

void GameState::setMonsters(vector<Monster*> inputMonsters){
	monsters = inputMonsters;
}

vector<Monster*> GameState::getMonsters(){
	return monsters;
}