#include "PatternsLib/PizzaStore.h"
#include "PatternsLib/Pizza.h"

namespace Patterns {

  PizzaStore::~PizzaStore() {

  }

  std::unique_ptr<Pizza> PizzaStore::orderPizza(std::string type) {
    auto pizza = createPizza(type);
    if (pizza) {
      pizza->prepare();
      pizza->bake();
      pizza->cut();
      pizza->box();
    }
    return pizza;
  }

}  // namespace Patterns