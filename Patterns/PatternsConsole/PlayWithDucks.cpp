#include "PatternsConsole/PlayWithDucks.h"
#include "PatternsLib/MallardDuck.h"
#include "PatternsLib/ModelDuck.h"
#include "PatternsLib/FlyRocketPowered.h"


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
