/**
 * @file DiceRoller.h
 * @brief Define class of ClassRoller.
 * @author Samuel RRJ Masuy
 * @version 1.0
 * @date 2016-10-18
 */
#pragma once
#include "Dice.h"
#include <regex>
#include <string>
#include <vector>

class DiceRoller {
 public:
  DiceRoller();
  ~DiceRoller();

  int roll(const std::string&);
  inline std::vector<Dice*> &getDices() {
    return dices;
  }
  inline int getModifier() {
    return modifier;
  }

 private:
  std::smatch matchQueryString(const std::string&);
  int validate_sides(int);
  void setDices(int, int);
  void setModifierFunction(const std::string);
  void setRules(const std::string&);
  std::vector<Dice*> dices;
  int(*modifier_func)(int, int);
  int modifier;
};


int add(int r, int n);

int substract(int r, int n);
