#pragma once
#include "PatternsLib/Pizza.h"

namespace Patterns {

  class CheesePizza : public Pizza {
  public:
    CheesePizza() : Pizza("CheesePizza", "Normal dough", "Tomato sauce") {
      addTopping("Grated Mozzarella Cheese");
    }
  };

}  // namespace Patterns
