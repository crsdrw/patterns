#pragma once

#include <iostream>

namespace AntiPatterns {
  class Duck {
  public:
    virtual void display() const = 0;
    virtual void fly() { std::cout << "Fly\n"; }  // made virtual so that rubber duck can override
    virtual void quack() { std::cout << "Quack\n"; }  // made virtual so that rubber duck can override
    void         swim() { std::cout << "All ducks float, even decoys!\n"; }
  };
}