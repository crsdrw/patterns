#pragma once
#include "PatternsLib/Pizza.h"
#include "PatternsLib/PizzaIngredientFactory.h"
#include <iostream>

namespace Patterns {

  class ClamPizza : public Pizza {
  private:
    std::unique_ptr<PizzaIngredientFactory> ingredient_factory_;
  public:
    ClamPizza(std::string name, std::unique_ptr<PizzaIngredientFactory> ingredient_factory)
      : Pizza(std::move(name)), ingredient_factory_(std::move(ingredient_factory)) {}
    
    void prepare() {
      std::cout << "Preparing " << getName() << std::endl;
      setDough(ingredient_factory_->createDough());
      setSauce(ingredient_factory_->createSauce());
      setCheese(ingredient_factory_->createCheese());
      setClam(ingredient_factory_->createClam());
    }

  };

}  // namespace Patterns