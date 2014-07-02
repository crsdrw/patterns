#include "PatternsLib/Pizza/NYPizzaStore.h"
#include "PatternsLib/Pizza/NYStyleCheesePizza.h"
#include "PatternsLib/Pizza/NYStylePepperoniPizza.h"
#include <memory>

namespace Patterns {

  std::unique_ptr<Pizza>
  NYPizzaStore::createPizza(std::string type) {
    if (type == "cheese")
      return std::make_unique<NYStyleCheesePizza>();
    else if (type == "pepperoni")
      return std::make_unique<NYStylePepperoniPizza>();
    return nullptr;
  }

}  // namespace Patterns