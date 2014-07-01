#pragma once
#include "PatternsLib/Pizza.h"
#include "PatternsLib/PizzaIngredientFactory.h"
#include <iostream>

namespace Patterns {

  class ClamPizza : public Pizza {
  private:
    std::unique_ptr<PizzaIngredientFactory> ingredient_factory_;
  public:
    ClamPizza(std::string name, std::unique_ptr<PizzaIngredientFactory> ingredient_factory);
    void prepare() override;
  };

}  // namespace Patterns