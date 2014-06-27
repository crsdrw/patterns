#pragma once
#include "PatternsLib/Beverage.h"

namespace Patterns {

  class Decaf : public Beverage {
  public:
    Decaf() : Beverage("Decaf") {}
    double cost() const override { return 1.05; }
  };

}  // namespace Patterns
