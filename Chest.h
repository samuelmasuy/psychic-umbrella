/**
 * @file Chest.h
 * @brief Definition for a chest.
 */
#pragma once
#include "Item.h"

/**
 * @brief Chest class, it is on the map and it contains items.
 */
class Chest {
 public:
   /**
    * @brief Constructor
    */
  Chest();
  /**
   * @brief place chest with specific items with position
   *
   * @param int positionX
   * @param int positionY
   * @param Item pointer to an item.
   */
  Chest(int, int, Item*);
  /**
   * @brief Chest destructor
   */
  ~Chest();
  /**
   * @brief Set X position of the chest.
   *
   * @param int positionX
   */
  void setPositionX(int);
  /**
   * @brief Set Y position of the chest.
   *
   * @param int positionY
   */
  void setPositionY(int);
  /**
   * @brief Set the content of a chest. (i.e) an item
   *
   * @param Item pointer to item
   */
  void setChestContent(Item*);
  /**
   * @brief Get X postion of the chest
   *
   * @return positionX
   */
  int getPositionX();
  /**
   * @brief Get Y postion of the chest
   *
   * @return positionY
   */
  int getPositionY();
  /**
   * @brief Get Item in the chest
   *
   * @return an item that is the chest.
   */
  Item* getItem();

 private:
  int positionX;
  int positionY;
  Item* chestContent;
};

