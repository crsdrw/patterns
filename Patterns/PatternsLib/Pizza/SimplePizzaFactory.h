#pragma once
#include <memory>
#include <string>

namespace Patterns {
  class Pizza;

  class SimplePizzaFactory {
  public:
    std::unique_ptr<Pizza> createPizza(std::string type) const;
  };

}  // namespace Patterns