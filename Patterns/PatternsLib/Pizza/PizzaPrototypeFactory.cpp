#include "PatternsLib/Pizza/PizzaPrototypeFactory.h"

namespace Patterns {

  PizzaPrototypeFactory::PizzaPrototypeFactory(std::unique_ptr<PizzaV0> prototype_pizza)
    : prototype_pizza_(std::move(prototype_pizza)) {

  }

  std::unique_ptr<PizzaV0>
  PizzaPrototypeFactory::makePizza() const {
    return prototype_pizza_->clone();
  }

} // namespace Patterns