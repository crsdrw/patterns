#pragma once
#include "PatternsLib/Decorator/Beverage.h"

namespace Patterns {

  class HouseBlend : public Beverage {
  public:
    HouseBlend() : Beverage("House Blend Coffee") {}
    double cost() const override { return 1.99; }
  };

}  // namespace Patterns