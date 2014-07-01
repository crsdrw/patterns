#pragma once
#include "PatternsLib/Pizza.h"
#include "PatternsLib/PizzaIngredientFactory.h"

namespace Patterns {

  class CheesePizza : public Pizza {
  private:
    std::unique_ptr<PizzaIngredientFactory> ingredient_factory_;
  public:
    CheesePizza(std::string name, std::unique_ptr<PizzaIngredientFactory> ingredient_factory);
    void prepare() override;
  };

}  // namespace Patterns