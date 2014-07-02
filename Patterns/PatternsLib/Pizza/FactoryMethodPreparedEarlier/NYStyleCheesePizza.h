#pragma once
#include "PatternsLib/Pizza/Pizza.h"

namespace Patterns {

  class NYStyleCheesePizza : public Pizza {
  public:
    NYStyleCheesePizza() : Pizza("NY Style Sauce and Cheese Pizza", "Thin Crust Dough", "Marinara Sauce") {
      addTopping("Grated Reggiano Cheese");
    }
  };

}  // namespace Patterns