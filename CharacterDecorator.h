/**
 * @file CharacterDecorator.h
 * @brief Abstract Character Decorator
 * @author Samuel Masuy
 * @date 2016-11-24
 */
#pragma once

#include <string>
#include "Character.h"
#include "map"

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
  CharacterDecorator(Character *decoratedCharacter) {
    this->decoratedCharacter = decoratedCharacter;
  }
  virtual ~CharacterDecorator() {
  }
  /**
  * Provides the wrapper with the Character interface and delegates
  * its methods to the wrapped Character object.
  */
  // int getStrength() {
  //   return decoratedCharacter->getStrength();
  // }
  void unequip(string);
  void setEquippedItems(map<string, Character*>);
  map<string, Character*> getEquippedItems();
  // Character* remove(string);
  // bool isTypeExist(string);


  //logical game functions
   void setCharacterType(string type)
  {
	   decoratedCharacter->setCharacterType(type);
  }
   bool validateNewCharacter()
   {
	  return decoratedCharacter->validateNewCharacter();
   }
   void hit(int dmg)
   {
	   decoratedCharacter->hit(dmg);
   }
   int generateStats()
   {
	   return decoratedCharacter->generateStats();
   }
   void hpChange()
   {
	   decoratedCharacter->hpChange();
   }
   int abilityModifier(int ability)
   {
	   return decoratedCharacter->abilityModifier(ability);
  }
  int armorModifier()
   {
	  return decoratedCharacter->armorModifier();
  }
  //virtual int attackBonus();//class to be inherited
  void setAttackBonus()
  {
	  decoratedCharacter->setAttackBonus();
  }
  void playerInfo()
  {
	  decoratedCharacter->playerInfo();
  }

  bool equipFromBackpack(int i) {
	  return decoratedCharacter->equipFromBackpack(i);
  }
  bool unequipItem(string s) {
	  return decoratedCharacter->unequipItem(s);
  }
  bool equipItem(Item* i) {
	  return decoratedCharacter->equipItem(i);
  }
  void printBackPackItems() {
	  decoratedCharacter->printBackPackItems();
  }
  void addToBackpack(Item i) {
	  decoratedCharacter->addToBackpack(i);
  }
  void printEquippedItems() {
	  decoratedCharacter->printEquippedItems();
  }
  void levelUp()
  {
	  decoratedCharacter->levelUp();
  }

  //saving and loading character
  void saveCharacter()
  {
	  decoratedCharacter->saveCharacter();
  }
  void loadCharacter()
  {
	  decoratedCharacter->loadCharacter();
  }
  void setLevel(int lvl)
  {
	  decoratedCharacter->setLevel(lvl);
  }
  void setPositionX(int x)
  {
	  decoratedCharacter->setPositionX(x);
  }
  void setPositionY(int y)
  {
	  decoratedCharacter->setPositionY(y);
  }

  //game accessor methods
  int getHitPoints()
  {
	 return decoratedCharacter->getHitPoints();
  }
  int getLevel()
  {
	 return decoratedCharacter->getLevel();
  }
  int getPositionX()
  {
	  return decoratedCharacter->getPositionX();
  }
  int getPositionY()
  {
	  return decoratedCharacter->getPositionY();
  }

  //character accessor methods
  int getAttacksPerRound()
  {
	  return decoratedCharacter->getAttacksPerRound();
  }
  string getCharacterType()
  {
	  return decoratedCharacter->getCharacterType();
  }
  int* getAbilityScores()
  {
	  return decoratedCharacter->getAbilityScores();
  }
  int* getAttackBonus()
  {
	  return decoratedCharacter->getAttackBonus();
  }
  int getDamageBonus()
  {
	  return decoratedCharacter->getDamageBonus();
  }
  void setStrength(int str)
  {
	  decoratedCharacter->setStrength(str);
  }
  void setDexterity(int dex)
  {
	  decoratedCharacter->setDexterity(dex);
  }
  void setConstitution(int con)
  {
	  decoratedCharacter->setConstitution(con);
  }
  void setIntelligence(int intel)
  {
	  decoratedCharacter->setIntelligence(intel);
  }
  void setWisdom(int wis)
  {
	  decoratedCharacter->setWisdom(wis);
  }
  void setCharisma(int cha)
  {
	  decoratedCharacter->setCharisma(cha);
  }

  int getStrength()
  {
	  return decoratedCharacter->getStrength();
  }
  int getDexterity()
  {
	  return decoratedCharacter->getDexterity();
  }
  int getConstitution()
  {
	  return decoratedCharacter->getConstitution();
  }
  int getIntelligence()
  {
	  return decoratedCharacter->getIntelligence();
  }
  int getWisdom()
  {
	  return  decoratedCharacter->getWisdom();
  }
  int getCharisma()
  {
	  return decoratedCharacter->getCharisma();
  }

 protected:
  Character *decoratedCharacter;
  map<string, Character*> equipedItems;
};
