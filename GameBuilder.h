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
  /**
   * @brief Get the game, once it has been constructed
   *
   * @return a game.
   */
  Game* getGame();
  /**
   * @brief Create a new Game.
   */
  void constructGame();
  /**
   * @brief Set character an map of the game.
   *
   * @param Character pointer to character.
   * @param Map pointer to map.
   */
  void setCharacterAndMap(Character*, Map*);
 private:
  Game* game;
};

