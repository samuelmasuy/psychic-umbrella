/**
 * @file GameBuilder.h
 * @brief Definition of the GameBuilder, we construct a game
 * and add the character, and map to it.
 * @author samuel
 */
#include "GameBuilder.h"

Game* GameBuilder::getGame() {
  return game;
}

void GameBuilder::constructGame() {
  game = new Game();
}

void GameBuilder::setCharacterAndMap(Character* character, Map* map) {
  game->setCharacter(character);
  game->setMap(map);
}
