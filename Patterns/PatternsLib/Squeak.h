#pragma once

#include "PatternsLib/QuackBehaviour.h"
#include <iostream>

namespace Patterns {
  class Squeak : public QuackBehaviour {
   public:
    void quack() override { std::cout << "Squeak\n"; }
    static QuackBehaviour::Ptr create() { return QuackBehaviour::Ptr(new Squeak()); }
  };
}  // namespace Patterns
