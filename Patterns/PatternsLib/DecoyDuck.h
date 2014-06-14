#include "PatternsLib/Duck.h"
#include "PatternsLib/MuteQuack.h"
#include "PatternsLib/FlyNoWay.h"
#include <iostream>

namespace Patterns {
  class DecoyDuck : public Duck {
  public:
    DecoyDuck() {
      setFlyBehaviour(FlyNoWay::create());
      setQuackBehaviour(MuteQuack::create());
    }
    void display() const override { std::cout << "I'm a decoy Duck\n"; }
  };
}  // namespace Patterns
