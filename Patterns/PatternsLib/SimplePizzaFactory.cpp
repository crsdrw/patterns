#include "PatternsLib/SimplePizzaFactory.h"
#include "PatternsLib/PizzaV0.h"
#include "PatternsLib/CheesePizzav0.h"
#include "PatternsLib/PepperoniPizzaV0.h"

namespace Patterns {

  std::unique_ptr<PizzaV0>
  SimplePizzaFactory::createPizza(std::string type) const {
    std::unique_ptr<PizzaV0> pizza;
    if (type == "cheese") {
      pizza = std::make_unique<CheesePizzav0>();
    } else if (type == "pepperoni") {
      pizza = std::make_unique<PepperoniPizzaV0>();
    }
    return pizza;
  }

}  // namespace Patterns