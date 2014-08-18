#pragma once
#include "PatternsLib/Pizza/PizzaV0.h"
#include <memory>

namespace Patterns {

  class PizzaPrototypeFactory {
  private:
    std::unique_ptr<PizzaV0> prototype_pizza_;
  public:
    PizzaPrototypeFactory(std::unique_ptr<PizzaV0> prototype_pizza);
    std::unique_ptr<PizzaV0> makePizza() const;
  };

}  // namespace Patterns