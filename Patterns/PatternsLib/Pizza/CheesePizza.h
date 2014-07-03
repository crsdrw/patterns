#pragma once
#include "PatternsLib/Pizza/Pizza.h"

namespace Patterns {

  class CheesePizza : public Pizza {
   public:
    CheesePizza() : Pizza("Cheese Pizza", "Regular crust dough", "Marinara sauce") {
      addTopping("Fresh Mozzarella");
      addTopping("Grated parmesan cheese");
    }
  };

}  // namespace Patterns
