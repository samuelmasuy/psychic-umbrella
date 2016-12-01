#include "GameState.h"

GameState::GameState(Character* inputCharacter, vector<Character*> inputMonsters, Map* inputMap) {
	mainCharacter = inputCharacter;
	monsters = inputMonsters;
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

void GameState::setMonsters(vector<Character*> inputMonsters){
	monsters = inputMonsters;
}

vector<Character*> GameState::getMonsters(){
	return monsters;
}