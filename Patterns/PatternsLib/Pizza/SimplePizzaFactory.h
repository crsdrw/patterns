#pragma once
#include <memory>
#include <string>

namespace Patterns {
  class PizzaV0;

  class SimplePizzaFactory {
  public:
    std::unique_ptr<PizzaV0> createPizza(std::string type) const;
  };

}  // namespace Patterns