#pragma once
#include "Enhancement.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Enhancement builder pattern, abstract class.
 */
class EnhancementBuilder {
 public:
  EnhancementBuilder();
  Enhancement* getEnhancement() {
    return enhancement;
  }
  void createNewEnhancment() {
    enhancement = new Enhancement();
  }
  virtual void buildType() = 0;
  void buildBonus();
  ~EnhancementBuilder();

 protected:
  Enhancement* enhancement;
};

/**
 * @brief Intelligence enhancement
 */
class IntelligenceEnhancementBuilder : public EnhancementBuilder {
  void buildType() {
    enhancement->setType("intelligence");
  }
};

/**
 * @brief Wisdom enhancement
 */
class WisdomEnhancementBuilder : public EnhancementBuilder {
  void buildType() {
    enhancement->setType("wisdom");
  }
};

/**
 * @brief Armor Enhancement
 */
class ArmorEnhancementBuilder : public EnhancementBuilder {
  void buildType() {
    enhancement->setType("armor");
  }
};

/**
 * @brief Stretgh Enhancement
 */
class StrentghEnhancementBuilder : public EnhancementBuilder {
  void buildType() {
    enhancement->setType("strength");
  }
};

/**
 * @brief Constitution Enhancement
 */
class ConstitutionEnhancementBuilder : public EnhancementBuilder {
  void buildType() {
    enhancement->setType("constitution");
  }
};

/**
 * @brief Charisma Enhancement
 */
class CharismaEnhancementBuilder : public EnhancementBuilder {
  void buildType() {
    enhancement->setType("charisma");
  }
};

/**
 * @brief Dexterity Enhancement
 */
class DexterityEnhancementBuilder : public EnhancementBuilder {
  void buildType() {
    enhancement->setType("dexterity");
  }
};

/**
 * @brief Damage Enhancement
 */
class DamageEnhancementBuilder : public EnhancementBuilder {
  void buildType() {
    enhancement->setType("damage");
  }
};

class RandomEnhancementBuilderForShield : public EnhancementBuilder {
  void buildType() {
    enhancement->setType("armor");
  }
};

class RandomEnhancementBuilderForArmor : public EnhancementBuilder {
  void buildType() {
    enhancement->setType("armor");
  }
};

class RandomEnhancementBuilderForHelmet : public EnhancementBuilder {
  void buildType();
};

class RandomEnhancementBuilderForRing : public EnhancementBuilder {
  void buildType();
};

class RandomEnhancementBuilderForBelt : public EnhancementBuilder {
  void buildType();
};

class RandomEnhancementBuilderForBoots : public EnhancementBuilder {
  void buildType();
};

class RandomEnhancementBuilderForWeapon : public EnhancementBuilder {
  void buildType();
};
