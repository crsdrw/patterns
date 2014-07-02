#pragma once

#include "PatternsLib/Strategy/QuackBehaviour.h"
#include <iostream>

namespace Patterns {
  class MuteQuack : public QuackBehaviour {
   public:
    void quack() override { std::cout << "<< Silence >>\n"; }
    static Ptr create() { return Ptr(new MuteQuack()); }
  };
}  // namespace Patterns
