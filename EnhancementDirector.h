#pragma once
#include "EnhancementBuilder.h"

class EnhancementDirector {
 public:
  EnhancementDirector();
  ~EnhancementDirector();
  void setEnhancementBuilder(EnhancementBuilder* inputEnhancementBuilder) {
    enhancementBuilder = inputEnhancementBuilder;
  };
  Enhancement getEnhancment() {
    enhancementBuilder->getEnhancement();
  };
  void constructEnhancement();


 private:
  EnhancementBuilder * enhancementBuilder;

};
