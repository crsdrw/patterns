#pragma once

#include "PatternsLib/Beverage.h"

namespace Patterns {
  class Espresso : public Beverage {
   public:
    Espresso() : Beverage("Espresso") {}
    double cost() const override { return 1.99; }
  };
}  // namespace Patterns