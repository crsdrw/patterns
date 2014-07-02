#include "PatternsConsole/PlayWithDucks.h"
#include "PatternsLib/Strategy/MallardDuck.h"
#include "PatternsLib/Strategy/ModelDuck.h"
#include "PatternsLib/Strategy/FlyRocketPowered.h"


namespace Patterns {
  void playWithDucks() {
    using Patterns::MallardDuck;
    using Patterns::ModelDuck;
    MallardDuck mallard;
    mallard.performQuack();
    mallard.performFly();

    ModelDuck model;
    model.performFly();
    model.setFlyBehaviour(Patterns::FlyRocketPowered::create());
    model.performFly();
  }
}
