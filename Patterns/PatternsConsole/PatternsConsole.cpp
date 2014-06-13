#include "PatternsLib/MallardDuck.h"
#include "PatternsLib/ModelDuck.h"
#include "PatternsLib/FlyRocketPowered.h"

int main() {
  using namespace Patterns;
  MallardDuck mallard;
  mallard.performQuack();
  mallard.performFly();

  ModelDuck model;
  model.performFly();
  model.setFlyBehaviour(FlyRocketPowered::create());
  model.performFly();
}

