#pragma once
#include "PatternsLib/PizzaV0.h"

namespace Patterns {
  class PepperoniPizzaV0 : public PizzaV0 {
  public:
    PepperoniPizzaV0() : PizzaV0("Pepperoni Pizza", "Normal dough", "Tomato sauce"){
      addTopping("Pepperoni");
    }
  };
}  // namespace Patterns