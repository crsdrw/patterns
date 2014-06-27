#include "PatternsConsole/MakePizza.h"
#include "PatternsLib/PizzaStoreV0.h"
#include "PatternsLib/SimplePizzaFactory.h"
#include "PatternsLib/Pizza.h"
#include <memory>

namespace Patterns {
  void makePizza() {
    SimplePizzaFactory factory;
    PizzaStoreV0 pizza_store(&factory);
    auto pizza1 = pizza_store.orderPizza("cheese");
    auto pizza2 = pizza_store.orderPizza("pepperoni");
  }
}  // namspace Patterns