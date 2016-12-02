/**
 * @file Dice.h
 * @brief Define Dice Class.
 * @author Samuel RRJ Masuy
 * @version 1.0
 * @date 2016-10-17
 */
#pragma once
#include <string>

class Dice {
 public:
  explicit Dice(int sides);
  ~Dice();
  int roll();
  inline int getResult() {
    return result;
  }
  inline int getSides() {
    return sides;
  }

 private:
  int sides;
  int result;
};
