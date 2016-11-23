/**
 * @file DoorBuilder.h
 * @brief Definition of the Builder pattern for the Door.
 */
#pragma once
#include "Door.h"

/**
 * @brief DoorBuilder class, it creates Doors
 */
class DoorBuilder {
 public:
  /**
   * @brief Constructor for a Door.
   */
  DoorBuilder();
  /**
   * @brief Build a new Door
   */
  void createNewDoor() {
    door = new Door();
  }
  /**
   * @brief Get Door that was built
   *
   * @return a Door
   */
  Door* getDoor() {
    return door;
  }
  /**
   * @brief Destructor for DoorBuilder.
   */
  ~DoorBuilder();

 private:
  Door* door;
};

