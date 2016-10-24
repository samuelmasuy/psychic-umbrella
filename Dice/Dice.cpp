/**
 * @file Dice.cpp
 * @brief Definition of a Dice, from d20 game.
 * @author Samuel RRJ Masuy
 * @version 1.0
 * @date 2016-10-17
 */
#include <iostream>
#include <string>
#include <stdlib.h> // srand, rand
#include <time.h>
#include <regex>

#include "Dice.h"
#include "DiceExceptions.h"

/**
 * @brief Constructor to create a Dice.
 *
 * @param sides: number of sides on the dice.
 */
Dice::Dice(int sides) {
  this->sides = sides;
}

Dice::~Dice() {
}

/**
 * @brief Roll the dice. i.e. Generate a random number between 1,
 * and the number of sides that the dice have.
 *
 * @return int: random number.
 */
int Dice::roll() {
  srand(time(NULL));
  int result = rand() % this->sides + 1;
  this->result = result;
  return result;
}
