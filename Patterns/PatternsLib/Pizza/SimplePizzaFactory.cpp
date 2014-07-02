#include "PatternsLib/Pizza/SimplePizzaFactory.h"
#include "PatternsLib/Pizza/Pizza.h"
#include "PatternsLib/Pizza/CheesePizza.h"
#include "PatternsLib/Pizza/PepperoniPizza.h"

namespace Patterns {

  std::unique_ptr<Pizza>
  SimplePizzaFactory::createPizza(std::string type) const {
    std::unique_ptr<Pizza> pizza;
    if (type == "cheese") {
      pizza = std::make_unique<CheesePizza>();
    } else if (type == "pepperoni") {
      pizza = std::make_unique<PepperoniPizza>();
    }
    return pizza;
  }

}  // namespace Patterns