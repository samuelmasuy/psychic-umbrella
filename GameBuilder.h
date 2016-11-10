/**
 * @file GameBuilder.h
 * @brief Definition of the Builder Pattern for the game.
 */
#pragma once

#include "Game.h"
#include "Map.h"
#include "Character.h"

class GameBuilder {
 public:
  Game* getGame();
  void constructGame();
  void setCharacterAndMap(Character*, Map*);
 private:
  Game* game;
};
