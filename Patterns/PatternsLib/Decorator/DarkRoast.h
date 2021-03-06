#pragma once
#include "PatternsLib/Decorator/Beverage.h"

namespace Patterns { 

  class DarkRoast : public Beverage {
  public:
    DarkRoast() : Beverage("Dark Roast") {}
    double cost() const override { return 0.99; }
  };

}  // namespace Patterns
