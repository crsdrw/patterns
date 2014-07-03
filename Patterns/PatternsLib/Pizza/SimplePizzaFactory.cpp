#include "PatternsLib/Pizza/SimplePizzaFactory.h"
#include "PatternsLib/Pizza/CheesePizza.h"
#include "PatternsLib/Pizza/PepperoniPizza.h"

namespace Patterns {

  std::unique_ptr<Pizza>
  createPizza(const std::string& type) {
    if (type == "cheese")
      return std::make_unique<CheesePizza>();
    
    if (type == "pepperoni")
      return std::make_unique<PepperoniPizza>();

    return nullptr;
  }

}  // namespace Patterns
