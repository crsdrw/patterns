#pragma once

#include <iostream>
#include "PatternsLib/SimUDuck/Duck.h"

namespace AntiPatterns {

  class RubberDuck : public Duck {
  public:
    void quack() override { std::cout << "Squeak\n"; }
    void display() const override { std::cout << "Looks like a rubber duck\n"; }
    void fly() override { std::cout << "I can't fly\n"; }
  };
}