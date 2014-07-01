#include "PatternsLib/ClamPizza.h"
#include "PatternsLib/Dough.h"
#include "PatternsLib/Sauce.h"
#include "PatternsLib/Cheese.h"
#include "PatternsLib/Clam.h"
#include <iostream>

namespace Patterns {

  ClamPizza::ClamPizza(std::string name, std::unique_ptr<PizzaIngredientFactory> ingredient_factory)
    : Pizza(std::move(name)), ingredient_factory_(std::move(ingredient_factory)) {

  }

  void
  ClamPizza::prepare() {
    std::cout << "Preparing " << getName() << std::endl;
    setDough(ingredient_factory_->createDough());
    setSauce(ingredient_factory_->createSauce());
    setCheese(ingredient_factory_->createCheese());
    setClam(ingredient_factory_->createClam());
  }

}  // namespace Patterns