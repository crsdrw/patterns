#pragma once
#include "PatternsLib/Pizza/Pizza.h"

namespace Patterns {

  class NYStylePepperoniPizza : public Pizza {
  public:
    NYStylePepperoniPizza() : Pizza("NY Style Sauce and Cheese Pizza", "Thin Crust Dough", "Marinara Sauce") {
      addTopping("Grated Reggiano Cheese");
      addTopping("Sliced Pepperoni");
      addTopping("Garlic");
      addTopping("Onion");
      addTopping("Mushrooms");
      addTopping("Red Pepper");
    }
  };

}  // namespace Patterns