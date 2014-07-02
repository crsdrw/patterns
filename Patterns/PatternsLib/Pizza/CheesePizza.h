#pragma once
#include "PatternsLib/Pizza/Pizza.h"

namespace Patterns {

  class CheesePizza : public Pizza {
  public:
    CheesePizza(std::string name, std::unique_ptr<PizzaIngredientFactory> ingredient_factory);
    void prepare() override;
  };

}  // namespace Patterns