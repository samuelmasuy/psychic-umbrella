/**
 * @file DoorDirector.h
 * @brief Definition of DoorDirector for builder pattern.
 */
#pragma once
#include "DoorBuilder.h"

/**
 * @brief Door Director.
 */
class DoorDirector {
 public:
  /**
   * @brief Default Constructor for DoorDirector
   */
  DoorDirector();

  /**
   * @brief Destructor for DoorDirector
   */
  ~DoorDirector();

  /**
   * @brief Set a concrete builder
   *
   * @param inputDoorBuilder
   */
  void setDoorBuilder(DoorBuilder* inputDoorBuilder) {
    DoorBuilder = inputDoorBuilder;
  };

  /**
   * @brief Ask the builder to return the Door it created.
   *
   * @return a Door
   */
  Door* getDoor() {
    return DoorBuilder->getDoor();
  };

  /**
   * @brief ask the builder to create a Door.
   */
  void makeDoor() {
    DoorBuilder->createNewDoor();
  };

 private:
  DoorBuilder* DoorBuilder;

};

