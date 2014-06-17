#pragma once

#include <iostream>
#include "PatternsLib/SimUDuck/Duck.h"

namespace AntiPatterns {

  class DecoyDuck : public Duck {
  public:
    void quack() override { std::cout << "<< Silence >>\n"; }
    void display() const override { std::cout << "Looks like a decoy duck\n"; }
    void fly() override { std::cout << "I can't fly\n"; } // duplicated from RubberDuck
  };
}