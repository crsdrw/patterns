#include "PatternsLib/Duck.h"
#include "PatternsLib/Squeak.h"
#include "PatternsLib/FlyNoWay.h"
#include <iostream>

namespace Patterns {
  class RubberDuck : public Duck {
  public:
    RubberDuck() {
      setFlyBehaviour(FlyNoWay::create());
      setQuackBehaviour(Squeak::create());
    }
    void display() const override { std::cout << "I'm a rubber Duck\n"; }
  };
}  // namespace Patterns
