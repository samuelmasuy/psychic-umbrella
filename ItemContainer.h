#ifndef ITEMCONTAINER_H
#define ITEMCONTAINER_H

#include <string>
#include <vector>
#include "Item.h"
using namespace std;

/**
 * @brief Item container, for example a chest
 */
class ItemContainer {
 public:
  ItemContainer();
  ItemContainer(vector<Item> items);
  // ~ItemContainer();
  vector<Item> getItems();
  void addItem(Item item);
  Item getItem(string itemType);
  bool validateItemsInContainer();

  // added
  int getSize();
  void removeItem(string itemType);
  int getItemIndex(string);
  void printBackpack();

 private:
  vector<Item> items;
  int size;
};

#endif

