#include "PatternsLib/Pizza/PizzaStore.h"
#include "PatternsLib/Pizza/SimplePizzaFactory.h"
#include "PatternsLib/Pizza/Pizza.h"

namespace Patterns {

  std::unique_ptr<Pizza>
  PizzaStore::orderPizza(const std::string& type) {
    std::unique_ptr<Pizza> pizza = createPizza(type);
    if (pizza) {
      pizza->prepare();
      pizza->bake();
      pizza->cut();
      pizza->box();
    }
    return pizza;
  }

}  // namespace Patterns