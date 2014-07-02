#pragma once
#include "PatternsLib/Decorator/Beverage.h"

namespace Patterns {

  class CondimentDecorator : public Beverage {
   public:
    std::string getDescription() const override = 0;
  };

}  // namespace Patterns
