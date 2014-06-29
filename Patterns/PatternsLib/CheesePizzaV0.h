#pragma once
#include "PatternsLib/PizzaV0.h"

namespace Patterns {

  class CheesePizzav0 : public PizzaV0 {
  public:
    CheesePizzav0() : PizzaV0("CheesePizza", "Normal dough", "Tomato sauce") {
      addTopping("Grated Mozzarella Cheese");
    }
  };

}  // namespace Patterns
