#pragma once
#include "PatternsLib/Pizza/Pizza.h"

namespace Patterns {
  class PepperoniPizza : public Pizza {
   public:
    PepperoniPizza() : Pizza("Pepperoni Pizza", "Regular crust dough", "Tomato sauce"){
      addTopping("Sliced Pepperoni");
      addTopping("Sliced Onion");
      addTopping("Grated parmesan cheese");
    }
  };
}  // namespace Patterns
