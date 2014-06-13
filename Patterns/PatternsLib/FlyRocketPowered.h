#pragma once

#include "PatternsLib/FlyBehaviour.h"
#include <iostream>

namespace Patterns {
  class FlyRocketPowered : public FlyBehaviour {
  public:
    void fly() override { std::cout << "I'm flying with a rocket!\n"; }
    static FlyBehaviour::Ptr create() { return FlyBehaviour::Ptr(new FlyRocketPowered()); }
  };
}  // namespace Patterns