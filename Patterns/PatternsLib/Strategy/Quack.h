#pragma once

#include "PatternsLib/Strategy/QuackBehaviour.h"
#include <iostream>

namespace Patterns {
  class Quack : public QuackBehaviour {
   public:
    void quack() override { std::cout << "Quack\n"; }
    static QuackBehaviour::Ptr create() { return QuackBehaviour::Ptr(new Quack()); }
  };
}  // namespace Patterns
