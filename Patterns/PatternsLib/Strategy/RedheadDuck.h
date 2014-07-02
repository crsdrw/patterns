#include "PatternsLib/Strategy/Duck.h"
#include "PatternsLib/Strategy/Quack.h"
#include "PatternsLib/Strategy/FlyWithWings.h"
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
