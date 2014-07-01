#include "PatternsLib/ClamPizza.h"
#include "PatternsLib/Dough.h"
#include "PatternsLib/Sauce.h"
#include "PatternsLib/Cheese.h"
#include "PatternsLib/Clam.h"
#include "PatternsLib/PizzaIngredientFactory.h"
#include <iostream>

namespace Patterns {

  ClamPizza::ClamPizza(std::string name, std::unique_ptr<PizzaIngredientFactory> ingredient_factory)
    : Pizza(std::move(name), std::move(ingredient_factory)) {

  }

  void
  ClamPizza::prepare() {
    std::cout << "Preparing " << getName() << std::endl;
    setDough(getIngredientFactory()->createDough());
    setSauce(getIngredientFactory()->createSauce());
    setCheese(getIngredientFactory()->createCheese());
    setClam(getIngredientFactory()->createClam());
  }

}  // namespace Patterns