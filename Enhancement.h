#pragma once

#include <string>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

/**
 * @brief An enhancement is something that benificiate a character.
 */
class Enhancement {
 public:
  /**
   * @brief Constructor
   */
  Enhancement();

  /**
   * @brief Constructor
   *
   * @param type enhancement type
   * @param bonus bonus
   */
  Enhancement(string type, int bonus);
  string getType();
  void setType(string);
  void setBonus(int);
  int getBonus();
  void setEnhancement(string, int);
  ~Enhancement();

 private:
  string type;
  int bonus;
};
