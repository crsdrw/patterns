#pragma once

#include "PatternsLib/FlyBehaviour.h"
#include <iostream>

namespace Patterns {
  class FlyNoWay : public FlyBehaviour {
   public:
    void fly() override { std::cout << "I can't fly\n"; }
    static Ptr create() { return Ptr(new FlyNoWay()); }
  };
}  // namespace Patterns
