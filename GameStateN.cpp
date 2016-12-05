#include "GameStateN.h"



GameStateN::GameStateN() {
}


GameStateN::~GameStateN() {
}

GameStateN::GameStateN(Character* inputCharacter, vector<Character*> inputMonsters, Map* inputMap, vector<Chest*> inputChests) {
  mainCharacter = inputCharacter;
  monsters = inputMonsters;
  map = inputMap;
  chests = inputChests;
}

void GameStateN::setMap(Map* inputMap) {
  map = inputMap;
}

Map* GameStateN::getMap() {
  return map;
}

void GameStateN::setMainCharacter(Character* inputMainCharacter) {
  mainCharacter = inputMainCharacter;
}

Character* GameStateN::getMainCharacter() {
  return mainCharacter;
}

void GameStateN::setMonsters(vector<Character*> inputMonsters) {
  monsters = inputMonsters;
}

vector<Character*> GameStateN::getMonsters() {
  return monsters;
}

void GameStateN::setChests(vector<Chest*> inputChests) {
  chests = inputChests;
}

vector<Chest*> GameStateN::getChests() {
  return chests;
}
