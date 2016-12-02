#include "EnhancementBuilder.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

EnhancementBuilder::EnhancementBuilder() {
  enhancement = new Enhancement();
}


EnhancementBuilder::~EnhancementBuilder() {
  delete enhancement;
}

void RandomEnhancementBuilderForHelmet::buildType() {
  srand(time(NULL));
  int i = rand() % 3;
  switch (i) {
  case 0:
    enhancement->setType("intelligence");
    break;
  case 1:
    enhancement->setType("armor");
    break;
  case 2:
    enhancement->setType("shield");
    break;
  }
}

void RandomEnhancementBuilderForRing::buildType() {
  srand(time(NULL));
  int i = rand() % 5;
  switch (i) {
  case 0:
    enhancement->setType("armor");
    break;
  case 1:
    enhancement->setType("strength");
    break;
  case 2:
    enhancement->setType("constitution");
    break;
  case 3:
    enhancement->setType("wisdom");
    break;
  case 4:
    enhancement->setType("charisma");
    break;
  }
}

void RandomEnhancementBuilderForBelt::buildType() {
  srand(time(NULL));
  int i = rand() % 2;
  switch (i) {
  case 0:
    enhancement->setType("constitution");
    break;
  case 1:
    enhancement->setType("strength");
    break;
  }
}

void RandomEnhancementBuilderForBoots::buildType() {
  srand(time(NULL));
  int i = rand() % 2;
  switch (i) {
  case 0:
    enhancement->setType("armor");
    break;
  case 1:
    enhancement->setType("dexterity");
    break;
  }
}

void RandomEnhancementBuilderForWeapon::buildType() {
  srand(time(NULL));
  int i = rand() % 2;
  switch (i) {
  case 0:
    enhancement->setType("attack");
    break;
  case 1:
    enhancement->setType("damage");
    break;
  }
}

void EnhancementBuilder::buildBonus() {
  srand(time(NULL));
  enhancement->setBonus(rand() % 5 + 1);
}
