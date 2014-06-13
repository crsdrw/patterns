#pragma once

#include "PatternsLib/QuackBehaviour.h"
#include <iostream>

namespace Patterns {
  class MuteQuack : public QuackBehaviour {
  public:
    void quack() override { std::cout << "<< Silence >>\n"; }
    static QuackBehaviour::Ptr create() { return QuackBehaviour::Ptr(new MuteQuack()); }
  };
}  // namespace Patterns