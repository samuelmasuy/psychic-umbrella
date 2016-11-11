#pragma once
#include "ItemBuilder.h"

/**
 * @brief Item Director for builder pattern
 */
class ItemDirector {
 public:
  ItemDirector();
  void setItemBuilder(ItemBuilder* inputItemBuilder) {
    itemBuilder = inputItemBuilder;
  }
  Item * getItem() {
    return itemBuilder->getItem();
  }
  void makeItem();
  ~ItemDirector();

 private:
  ItemBuilder* itemBuilder;
};

