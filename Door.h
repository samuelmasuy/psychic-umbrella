/**
 * @file Door.h
 * @brief Definition for a Door.
 */
#pragma once

/**
 * @brief Door class, it is on the map and it contains items.
 */
class Door {
 public:
  /**
   * @brief Constructor
   */
  Door();
  /**
   * @brief place Door
   *
   * @param int positionX
   * @param int positionY
   */
  Door(int, int);
  /**
   * @brief Door destructor
   */
  ~Door();
  /**
   * @brief Set X position of the Door.
   *
   * @param int positionX
   */
  void setPositionX(int);
  /**
   * @brief Set Y position of the Door.
   *
   * @param int positionY
   */
  void setPositionY(int);
  /**
   * @brief Get X postion of the Door
   *
   * @return positionX
   */
  int getPositionX();
  /**
   * @brief Get Y postion of the Door
   *
   * @return positionY
   */
  int getPositionY();

 private:
  int positionX;
  int positionY;
};

