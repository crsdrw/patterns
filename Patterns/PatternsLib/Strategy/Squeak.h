#pragma once

#include "PatternsLib/Strategy/QuackBehaviour.h"
#include <iostream>

namespace Patterns {
  class Squeak : public QuackBehaviour {
   public:
    void quack() override { std::cout << "Squeak\n"; }
    static Ptr create() { return Ptr(new Squeak()); }
  };
}  // namespace Patterns
