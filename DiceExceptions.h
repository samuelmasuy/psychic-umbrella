/**
 * @file DiceExceptions.h
 * @brief Definition of some of dice exceptions.
 * @author Samuel RRJ Masuy
 * @version 1.0
 * @date 2016-10-18
 */
#pragma once
#include <iostream>
#include <exception>

/**
 * @brief Exception when user gives a wrong query format.
 */
struct InvalidQuerySring : public std::exception {
  const char * what() const throw() {
    return "Invalid Query Sring. Query String need to be of the following format: `xdy[+z]`";
  }
};


/**
 * @brief Exception when user gives wrong number of loops.
 */
struct InvalidNumberOfLoops : public std::exception {
  const char * what() const throw() {
    return "Invalid Number Of Loops.";
  }
};

/**
 * @brief Exception when user gives wrong number of sides to the dice.
 */
struct InvalidNumberOfSides : public std::exception {
  const char * what() const throw() {
    return "Invalid Number Of Sides of the dice. The dice must can either be: 4, 6, 8, 10, 12, 20 or 100.";
  }
};
