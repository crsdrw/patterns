#include "PatternsLib/Pizza/ClamPizza.h"
#include "PatternsLib/Pizza/Dough.h"
#include "PatternsLib/Pizza/Sauce.h"
#include "PatternsLib/Pizza/Cheese.h"
#include "PatternsLib/Pizza/Clam.h"
#include "PatternsLib/Pizza/PizzaIngredientFactory.h"
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