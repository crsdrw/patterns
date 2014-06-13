#include "PatternsLib/Duck.h"
#include "PatternsLib/Quack.h"
#include "PatternsLib/FlyNoWay.h"
#include <iostream>

namespace Patterns {
  class ModelDuck : public Duck {
  public:
    ModelDuck() : Duck(FlyNoWay::create(), Quack::create()) {}
    void display() const override { std::cout << "I'm a model Duck\n"; }
  };
}  // namespace Patterns