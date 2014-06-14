#pragma once

#include "PatternsLib/FlyBehaviour.h"
#include <iostream>

namespace Patterns {
  class FlyRocketPowered : public FlyBehaviour {
   public:
    void fly() override { std::cout << "I'm flying with a rocket!\n"; }
    static Ptr create() { return Ptr(new FlyRocketPowered()); }
  };
}  // namespace Patterns
