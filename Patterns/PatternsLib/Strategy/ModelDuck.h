#include "PatternsLib/Strategy/Duck.h"
#include "PatternsLib/Strategy/Quack.h"
#include "PatternsLib/Strategy/FlyNoWay.h"
#include <iostream>

namespace Patterns {
  class ModelDuck : public Duck {
   public:
    ModelDuck() {
      setFlyBehaviour(FlyNoWay::create());
      setQuackBehaviour(Quack::create());
    }
    void display() const override { std::cout << "I'm a model Duck\n"; }
  };
}  // namespace Patterns
