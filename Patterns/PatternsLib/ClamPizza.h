#pragma once
#include "PatternsLib/Pizza.h"

namespace Patterns {

  class ClamPizza : public Pizza {
  public:
    ClamPizza(std::string name, std::unique_ptr<PizzaIngredientFactory> ingredient_factory);
    void prepare() override;
  };

}  // namespace Patterns