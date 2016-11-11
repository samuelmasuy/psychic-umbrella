#pragma once
#include "Enhancement.h"
#include <stdio.h>
#include <stdlib.h>

class EnhancementBuilder
{
public:
	EnhancementBuilder();
	Enhancement* getEnhancement() { return enhancement; };
	void createNewEnhancment() { enhancement = new Enhancement(); };
	virtual void buildType() = 0;
	void buildBonus() { enhancement->setBonus(rand() % 7 + 1); };
	~EnhancementBuilder();

protected:
	Enhancement* enhancement;
};

class IntelligenceEnhancementBuilder : public EnhancementBuilder{
	void buildType() { enhancement->setType("intelligence"); };
};

class WisdomEnhancementBuilder : public EnhancementBuilder {
	void buildType() { enhancement->setType("wisdom"); };
};

class ArmorEnhancementBuilder : public EnhancementBuilder {
	void buildType() { enhancement->setType("armor"); };
};

class StrentghEnhancementBuilder : public EnhancementBuilder {
	void buildType() { enhancement->setType("strengh"); };
};

class ConstitutionEnhancementBuilder : public EnhancementBuilder {
	void buildType() { enhancement->setType("constitution"); };
};

class CharismaEnhancementBuilder : public EnhancementBuilder {
	void buildType() { enhancement->setType("charisma"); };
};

class DexterityEnhancementBuilder : public EnhancementBuilder {
	void buildType() { enhancement->setType("dexterity"); };
};

class DamageEnhancementBuilder : public EnhancementBuilder {
	void buildType() { enhancement->setType("damage"); };
};

class RandomEnhancementBuilderForShield : public EnhancementBuilder {
	void buildType() { enhancement->setType("armor"); };
};

class RandomEnhancementBuilderForArmor : public EnhancementBuilder {
	void buildType() { enhancement->setType("armor"); };
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