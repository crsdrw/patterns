#include "PatternsLib/Duck.h"
#include "PatternsLib/Quack.h"
#include "PatternsLib/FlyWithWings.h"
#include <iostream>

namespace Patterns {
  class MallardDuck : public Duck {
   public: 
    MallardDuck() : Duck(FlyWithWings::create(), Quack::create()) {}
    void display() const override { std::cout << "I'm a real Mallard Duck\n"; }
  };
}  // namespace Patterns
