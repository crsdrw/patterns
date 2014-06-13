#pragma once

#include "PatternsLib/FlyBehaviour.h"
#include <iostream>

namespace Patterns {
  class FlyWithWings : public FlyBehaviour {
   public:
    void fly() override { std::cout << "I'm flying!!\n"; }
    static FlyBehaviour::Ptr create() { return FlyBehaviour::Ptr(new FlyWithWings()); }
  };
}  // namespace Patterns
