#include "PatternsLib/Pizza/NYPizzaStore.h"
#include "PatternsLib/Pizza/NYPizzaIngredientFactory.h"
#include "PatternsLib/Pizza/CheesePizza.h"
#include "PatternsLib/Pizza/ClamPizza.h"

#include <memory>

namespace Patterns {

  std::unique_ptr<Pizza>
  NYPizzaStore::createPizza(std::string type) {
    auto ingredient_factory = std::make_unique<NYPizzaIngredientFactory>();
    if (type == "cheese")
      return std::make_unique<CheesePizza>("New York Style Cheese Pizza", std::move(ingredient_factory));
    else if (type == "clam")
      return std::make_unique<ClamPizza>("New York Style Clam Pizza", std::move(ingredient_factory));
    return nullptr;
  }

}  // namespace Patterns