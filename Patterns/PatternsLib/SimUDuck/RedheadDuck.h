#pragma once

#include <iostream>
#include "PatternsLib/SimUDuck/Duck.h"

namespace AntiPatterns {

  class RedheadDuck : public Duck {
  public:
    void display() const override { std::cout << "Looks like a redhead\n"; }
  };
}