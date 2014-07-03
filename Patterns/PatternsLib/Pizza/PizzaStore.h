#pragma once
#include "PatternsLib/Pizza/Pizza.h"
#include <memory>

namespace Patterns {

  class PizzaStore {
   public:
    std::unique_ptr<Pizza> orderPizza(const std::string& type);
  };

}  // namespace Patterns
