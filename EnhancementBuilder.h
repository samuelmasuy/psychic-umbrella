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

class intelligenceEnhancementBuilder : public EnhancementBuilder{
	void buildType() { enhancement->setType("intelligence"); };
};

class wisdomEnhancementBuilder : public EnhancementBuilder {
	void buildType() { enhancement->setType("wisdom"); };
};

class armorEnhancementBuilder : public EnhancementBuilder {
	void buildType() { enhancement->setType("armor"); };
};

class strentghEnhancementBuilder : public EnhancementBuilder {
	void buildType() { enhancement->setType("strengh"); };
};

class constitutionEnhancementBuilder : public EnhancementBuilder {
	void buildType() { enhancement->setType("constitution"); };
};

class charismaEnhancementBuilder : public EnhancementBuilder {
	void buildType() { enhancement->setType("charisma"); };
};

class dexterityEnhancementBuilder : public EnhancementBuilder {
	void buildType() { enhancement->setType("dexterity"); };
};

class damageEnhancementBuilder : public EnhancementBuilder {
	void buildType() { enhancement->setType("damage"); };
};