/**
 * @file ItemException.h
 * @brief Exception with items.
 * @author Samuel Masuy
 * @date 2016-11-24
 */
#pragma once

using namespace std;

/**
 * @brief Exception that occurs when a character is already wearing
 * an item.
 */
struct ItemAlreadyWornException : public exception {
  /**
   * @brief Exception message.
   *
   * @return a string with a message.
   */
  const char * what () const throw () {
    return "The chararacter is already wearing this item.";
  }
};
