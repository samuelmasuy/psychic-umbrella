/**
 * @file DiceRoller.cpp
 * @brief The Dice Roller is taking a rule from the user, and execute
 * this rule, by setting up dice, and rolling them all.
 * @author Samuel RRJ Masuy
 * @version 1.0
 * @date 2016-10-18
 */
#include <regex>
#include <stdio.h>

#include "DiceRoller.h"
#include "DiceExceptions.h"

DiceRoller::DiceRoller() {
}

DiceRoller::~DiceRoller() {
}

/**
 * @brief Roll a series of dice.
 *
 * @param rules: string: a pattern that match the following `xdy[+z]`.
 * Where x is the number of times the dice has to be rolled, d is a constant,
 * y is the kind of dice (number of sides on dice). And z is a modifier to
 * applied, once all dice are rolled.
 *
 * @return Final result.
 */
int DiceRoller::roll(const std::string &rules) {
  this->setRules(rules);
  int result = 0;
  for (auto const& dice : this->dices) {
    result += dice->roll();
  }
  return this->modifier_func(result, this->modifier);
}

/**
 * @brief Set rules of the game.
 *
 * @param rules: string: a pattern that match the following `xdy[+z]`.
 * Where x is the number of times the dice has to be rolled, d is a constant,
 * y is the kind of dice (number of sides on dice). And z is a modifier to
 * applied, once all dice are rolled.
 *
 * @throws InvalidNumberOfLoops, InvalidNumberOfSides
 */
void DiceRoller::setRules(const std::string &rules) {
  std::smatch match = this->matchQueryString(rules);

  // match[0] refers to the full match.
  int loops = stoi(match[1]);  // stoi, is to convert a string to an integer.
  int sides = stoi(match[2]);
  std::string sign = match[3];
  this->modifier = stoi(match[4]);

  if (!this->validate_sides(sides)) {
    // make sure the number of sides is valid.
    throw InvalidNumberOfSides();
  }
  if (loops <= 0) {
    throw InvalidNumberOfLoops();
  }

  this->setDices(sides, loops);
  this->setModifierFunction(sign);
}

/**
 * @brief Match query string versus a Regex. (see rules below).
 *
 * @param rules: string: a pattern that match the following `xdy[+z]`.
 * Where x is the number of times the dice has to be rolled, d is a constant,
 * y is the kind of dice (number of sides on dice). And z is a modifier to
 * applied, once all dice are rolled.
 *
 * @throws InvalidQuerySring
 *
 * @return an array of match that the regex found.
 */
std::smatch DiceRoller::matchQueryString(const std::string& query) {
  std::regex rgx("^(-?\\d+)d(\\d+)\\[([\\+\\|-])(\\d+)\\]$");
  std::smatch match;

  if (!std::regex_search(query, match, rgx)) {
    // no match were found.
    throw InvalidQuerySring();
  }
  return match;
}

/**
 * @brief Validate the number of sides of the dice.
 * The number of sides in d20 games, is either 4, 6, 8, 10, 12, 20 or 100.
 *
 * @param sides: int: given sides
 *
 * @return number of sides matches one of the dice found in d20 game.
 */
int DiceRoller::validate_sides(int sides) {
  return (sides == 4 || sides == 6 || sides == 8 || sides == 10 ||
          sides == 12 || sides == 20 || sides == 100);
}

/**
 * @brief Initialize Vector of Dice.
 *
 * @param sides The number of side of the dice.
 * @param loops The number of dice to be made.
 */
void DiceRoller::setDices(int sides, int loops) {
  for (int i = 0; i < loops; i++) {
    Dice* dice = new Dice(sides);
    this->dices.push_back(dice);
  }
}

/**
 * @brief Assign modifier function, it can either be an adder, or substracter.
 *
 * @param sign refers to the modifier sign.
 */
void DiceRoller::setModifierFunction(const std::string sign) {
  if (sign == "+") {
    this->modifier_func = &add;
  } else {
    this->modifier_func = &substract;
  }
}

/**
 * @brief Add two numbers.
 *
 * @param r
 * @param n
 *
 * @return r + n
 */
int add(int r, int n) {
  return r + n;
}

/**
 * @brief Substract a number from another.
 *
 * @param r
 * @param n
 *
 * @return r - n
 */
int substract(int r, int n) {
  return r - n;
}
