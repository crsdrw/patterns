#include "PatternsLib/Pizza/ChicagoPizzaStore.h"
#include "PatternsLib/Pizza/ChicagoPizzaIngredientFactory.h"
#include "PatternsLib/Pizza/CheesePizza.h"
#include "PatternsLib/Pizza/ClamPizza.h"
#include <memory>

namespace Patterns {

  std::unique_ptr<Pizza>
    ChicagoPizzaStore::createPizza(std::string type) {
    auto ingredient_factory = std::make_unique<ChicagoPizzaIngredientFactory>();
    if (type == "cheese")
      return std::make_unique<CheesePizza>("Chicago Style Cheese Pizza", std::move(ingredient_factory));
    else if (type == "clam")
      return std::make_unique<ClamPizza>("Chicago Style Cheese Pizza", std::move(ingredient_factory));
    return nullptr;
  }

}  // namespace Patterns