#pragma once

#include "PatternsLib/FlyBehaviour.h"
#include <iostream>

namespace Patterns {
  class FlyWithWings : public FlyBehaviour {
   public:
    void fly() override { std::cout << "I'm flying!!\n"; }
    static Ptr create() { return Ptr(new FlyWithWings()); }
  };
}  // namespace Patterns
