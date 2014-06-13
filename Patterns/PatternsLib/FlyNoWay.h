#pragma once

#include "PatternsLib/FlyBehaviour.h"
#include <iostream>

namespace Patterns {
  class FlyNoWay : public FlyBehaviour {
   public:
    void fly() override { std::cout << "I can't fly\n"; }
    static FlyBehaviour::Ptr create() { return FlyBehaviour::Ptr(new FlyNoWay()); }
  };
}  // namespace Patterns
