#pragma once
#include "PatternsLib/Pizza.h"

namespace Patterns {

  class NYStylePepperoniPizza : public Pizza {
  public:
    NYStylePepperoniPizza() : Pizza("NY Style Sauce and Cheese Pizza", "Thin Crust Dough", "Marinara Sauce") {
      addTopping("Thinly Sliced Pepperoni");
    }
  };

}  // namespace Patterns