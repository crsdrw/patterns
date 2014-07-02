#include "PatternsLib/Strategy/Duck.h"
#include "PatternsLib/Strategy/Quack.h"
#include "PatternsLib/Strategy/FlyWithWings.h"
#include <iostream>

namespace Patterns {
  class MallardDuck : public Duck {
   public: 
    MallardDuck() {
      setFlyBehaviour(FlyWithWings::create());
      setQuackBehaviour(Quack::create());
    }
    void display() const override { std::cout << "I'm a real Mallard Duck\n"; }
  };
}  // namespace Patterns
