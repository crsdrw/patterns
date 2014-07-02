#pragma once
#include "PatternsLib/Pizza/Pizza.h"

namespace Patterns {
  class PepperoniPizza : public Pizza {
  public:
    PepperoniPizza() : Pizza("Pepperoni Pizza", "Normal dough", "Tomato sauce"){
      addTopping("Pepperoni");
    }
  };
}  // namespace Patterns