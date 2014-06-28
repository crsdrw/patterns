#include "PatternsLib/ChicagoPizzaStore.h"
#include "PatternsLib/ChicagoStyleCheesePizza.h"
#include "PatternsLib/ChicagoStylePepperoniPizza.h"
#include <memory>

namespace Patterns {

  std::unique_ptr<Pizza>
    ChicagoPizzaStore::createPizza(std::string type) {
    if (type == "cheese")
      return std::make_unique<ChicagoStyleCheesePizza>();
    else if (type == "pepperoni")
      return std::make_unique<ChicagoStylePepperoniPizza>();
    return nullptr;
  }

}  // namespace Patterns