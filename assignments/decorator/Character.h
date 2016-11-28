/**
 * @file Character.h
 * @brief Character class and Fighter class.
 * @author Samuel Masuy
 * @date 2016-11-24
 */
#pragma once

#include <string>

using namespace std;

/**
* @brief The abstract Character class defines the functionality of any Character
* implemented by subclasses of Character.
*/
class Character {
 public:
  virtual int getStrength() = 0;
  virtual int getArmor() = 0;
  virtual int getConstitution() = 0;
  virtual int getWisdom() = 0;
  virtual int getCharisma() = 0;
  virtual int getDexterity() = 0;
  virtual int getAttack() = 0;
  virtual int getDamage() = 0;
  virtual int getIntelligence() = 0;
  /**
   * @brief Remove an item from the character.
   *
   * @param string Type of item.
   *
   * @return a character without the item passed,
   * *warning*, when removing an item that is not on
   * top of the stack it will remove all the subsequent
   * items.
   */
  virtual Character* remove(string) = 0;
  /**
   * @brief Check if the character already have an item.
   *
   * @param string Type of item
   *
   * @return true if character wears the item, false
   * otherwise.
   */
  virtual bool isTypeExist(string) = 0;
};

/**
 * @brief Fighter is the a kind of Character.
 */
class Fighter : public Character {
 public:
  int getStrength();
  int getArmor();
  int getConstitution();
  int getWisdom();
  int getCharisma();
  int getDexterity();
  int getAttack();
  int getDamage();
  int getIntelligence();
  Character* remove(string);
  bool isTypeExist(string);
};
