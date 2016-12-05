/**
 * @file ChestDirector.h
 * @brief Definition of ChestDirector for builder pattern.
 */
#pragma once
#include "ChestBuilder.h"

/**
 * @brief Chest Director.
 */
class ChestDirector {
 public:
  /**
   * @brief Default Constructor for ChestDirector
   */
  ChestDirector();

  /**
   * @brief Destructor for ChestDirector
   */
  ~ChestDirector();

  /**
   * @brief Set a concrete builder
   *
   * @param inputChestBuilder
   */
  void setChestBuilder(ChestBuilder* inputChestBuilder) {
    chestBuilder = inputChestBuilder;
  };

  /**
   * @brief Ask the builder to return the chest it created.
   *
   * @return a chest
   */
  Chest* getChest() {
    return chestBuilder->getChest();
  };

  /**
   * @brief ask the builder to create a chest.
   */
  void makeChest() {
    chestBuilder->createNewChest();
  };

 private:
  ChestBuilder* chestBuilder;

};

