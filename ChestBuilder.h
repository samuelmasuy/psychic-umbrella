/**
 * @file ChestBuilder.h
 * @brief Definition of the Builder pattern for the chest.
 */
#pragma once
#include "Chest.h"
#include "ItemDirector.h"

/**
 * @brief ChestBuilder class, it creates chests
 */
class ChestBuilder {
 public:
  /**
   * @brief Constructor for a chest.
   */
  ChestBuilder();
  /**
   * @brief Build a new chest
   */
  void createNewChest() {
    chest = new Chest();
    buildItem();
  }
  /**
   * @brief Get chest that was built
   *
   * @return a chest
   */
  Chest* getChest() {
    return chest;
  }
  /**
   * @brief Build the Item.
   */
  void buildItem();
  /**
   * @brief Destructor for ChestBuilder.
   */
  ~ChestBuilder();

 private:
  Chest* chest;
};

