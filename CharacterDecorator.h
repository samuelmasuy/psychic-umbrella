/**
 * @file CharacterDecorator.h
 * @brief Abstract Character Decorator
 * @author Samuel Masuy
 * @date 2016-11-24
 */
#pragma once

#include <iostream>
#include <string>
#include "Character.h"
/**
 * @brief Abstract decorator class - note that it extends the Character abstract class.
 */
class CharacterDecorator : public Character {
 public:
  /**
   * @brief Wraps a Character object inside an object of one of
   * CharacterDecorator's subclasses
   *
   * @param decoratedCharacter a Character.
   */
  CharacterDecorator(Character *decoratedCharacter, Item* item) {
    this->decoratedCharacter = decoratedCharacter;
    this->item = item;
  }
  virtual ~CharacterDecorator() {
  }
  /**
  * Provides the wrapper with the Character interface and delegates
  * its methods to the wrapped Character object.
  */
  void playerInfo();

  //logical game functions
  void setCharacterType(string type) {
    decoratedCharacter->setCharacterType(type);
  }
  bool validateNewCharacter() {
    return decoratedCharacter->validateNewCharacter();
  }
  void hit(int dmg) {
    decoratedCharacter->hit(dmg);
  }
  int generateStats() {
    return decoratedCharacter->generateStats();
  }
  void hpChange() {
    decoratedCharacter->hpChange();
  }
  int abilityModifier(int ability) {
    return decoratedCharacter->abilityModifier(ability);
  }
  int armorModifier() {
    return decoratedCharacter->armorModifier();
  }

  void setArmor() {
    return decoratedCharacter->setArmor();
  }
  //virtual int attackBonus();//class to be inherited
  void setAttackBonus() {
    decoratedCharacter->setAttackBonus();
  }
  void printBackPackItems() {
    return decoratedCharacter->printBackPackItems();
  }

  void addToBackpack(Item* i) {
    decoratedCharacter->addToBackpack(i);
  }

  void levelUp() {
    decoratedCharacter->levelUp();
  }
  //void setStrategy(StrategyN* inputStrategy){
//	  decoratedCharacter->setStrategy(inputStrategy);
  //}

  //StrategyN* getStrategy(){
  // return decoratedCharacter->getStrategy();
  //}

  void printEquippedItems();

  Item* retrieveItem(string);

  void setLevel(int lvl) {
    decoratedCharacter->setLevel(lvl);
  }
  void setPositionX(int x) {
    decoratedCharacter->setPositionX(x);
  }
  void setPositionY(int y) {
    decoratedCharacter->setPositionY(y);
  }

  //game accessor methods
  int getHitPoints() {
    return decoratedCharacter->getHitPoints();
  }
  int getLevel() {
    return decoratedCharacter->getLevel();
  }
  int getPositionX() {
    return decoratedCharacter->getPositionX();
  }
  int getPositionY() {
    return decoratedCharacter->getPositionY();
  }

  //character accessor methods
  int getAttacksPerRound() {
    return decoratedCharacter->getAttacksPerRound();
  }
  string getCharacterType() {
    return decoratedCharacter->getCharacterType();
  }
  int* getAbilityScores() {
    return decoratedCharacter->getAbilityScores();
  }

  int getAbilityScore(int ability) {
    return decoratedCharacter->getAbilityScore(ability);
  }
  int* getAttackBonus() {
    return decoratedCharacter->getAttackBonus();
  }
  int getDamageBonus() {
    return decoratedCharacter->getDamageBonus();
  }
  void setStrength(int str) {
    decoratedCharacter->setStrength(str);
  }
  void setDexterity(int dex) {
    decoratedCharacter->setDexterity(dex);
  }
  void setConstitution(int con) {
    decoratedCharacter->setConstitution(con);
  }
  void setIntelligence(int intel) {
    decoratedCharacter->setIntelligence(intel);
  }
  void setWisdom(int wis) {
    decoratedCharacter->setWisdom(wis);
  }
  void setCharisma(int cha) {
    decoratedCharacter->setCharisma(cha);
  }
  int getStrength() {
    return decoratedCharacter->getStrength();
  }
  int getDexterity() {
    return decoratedCharacter->getDexterity();
  }
  int getConstitution() {
    return decoratedCharacter->getConstitution();
  }
  int getIntelligence() {
    return decoratedCharacter->getIntelligence();
  }
  int getWisdom() {
    return  decoratedCharacter->getWisdom();
  }
  int getCharisma() {
    return decoratedCharacter->getCharisma();
  }

  void combat(Character* m) {
    decoratedCharacter->combat(m);
  }

  void setHitPoints(int hp) {
    decoratedCharacter->setHitPoints(hp);
  }
  ItemContainer getBackPack() {
    return decoratedCharacter->getBackPack();
  }

  void setAbilityScores(int i, int abl) {
    decoratedCharacter->setAbilityScores(i, abl);
  }
 protected:
  Character* decoratedCharacter;
  Item* item;
};
