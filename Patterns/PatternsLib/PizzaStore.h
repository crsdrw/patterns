#pragma once

#include <memory>
#include <string>

namespace Patterns {
  class Pizza;

  class PizzaStore {
   protected:
    virtual std::unique_ptr<Pizza> createPizza(std::string type) = 0;  // astract factory method
   public:
    std::unique_ptr<Pizza> orderPizza(std::string type);
  };

}  // namespace Patterns
