#include "PatternsLib/Duck.h"
#include "PatternsLib/Quack.h"
#include "PatternsLib/FlyWithWings.h"
#include <iostream>

namespace Patterns {
  class RedheadDuck : public Duck {
  public:
    RedheadDuck() {
      setFlyBehaviour(FlyWithWings::create());
      setQuackBehaviour(Quack::create());
    }
    void display() const override { std::cout << "I'm a real Redhead Duck\n"; }
  };
}  // namespace Patterns
