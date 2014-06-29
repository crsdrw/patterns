#pragma once
#include "PatternsLib/Pizza.h"
#include "PatternsLib/PizzaIngredientFactory.h"
#include <iostream>

namespace Patterns {

  class CheesePizza : public Pizza {
  private:
    std::unique_ptr<PizzaIngredientFactory> ingredient_factory_;
  public:
    CheesePizza(std::unique_ptr<PizzaIngredientFactory> ingredient_factory)
      : ingredient_factory_(std::move(ingredient_factory)) :{}
    void prepare() {
      std::cout << "Preparing " << getName() << std::endl;
      dough_ = ingredient_factory_->createDough();
      sauce_ = ingredient_factory_->createSauce();
      cheese_ = ingredient_factory_->creageCheese();
    }
  };

}  // namespace Patterns