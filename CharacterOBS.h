#pragma once
#include "Character.h"
#include "Observer.h"

/**
 * @brief Observer pattern for character
 */
class CharacterOBS : public Observer {
 public:
  /**
   * @brief constructor
   */
  CharacterOBS();
  /**
   * @brief Constructor taking a character.
   *
   * @param theCharacter
   */
  CharacterOBS(Character* theCharacter);
  /**
   * @brief Destructor
   */
  virtual ~CharacterOBS();
  /**
   * @brief Print the character info.
   */
  void printPlayerInfo();
  /**
   * @brief Call when the character is updated.
   */
  void update();

 private:
  Character* character;
};

