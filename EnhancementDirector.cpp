#include "EnhancementDirector.h"

EnhancementDirector::EnhancementDirector() {
}


EnhancementDirector::~EnhancementDirector() {
}

void EnhancementDirector::constructEnhancement() {
  enhancementBuilder->createNewEnhancment();
  enhancementBuilder->buildBonus();
  enhancementBuilder->buildType();
}
