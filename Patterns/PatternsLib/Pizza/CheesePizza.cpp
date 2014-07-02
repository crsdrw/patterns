#include "PatternsLib/Pizza/CheesePizza.h"
#include "PatternsLib/Pizza/Dough.h"
#include "PatternsLib/Pizza/Sauce.h"
#include "PatternsLib/Pizza/Cheese.h"
#include "PatternsLib/Pizza/PizzaIngredientFactory.h"

#include <iostream>

namespace Patterns {

  CheesePizza::CheesePizza(std::string name, std::unique_ptr<PizzaIngredientFactory> ingredient_factory)
    : Pizza(std::move(name), std::move(ingredient_factory)) {
  
  }

  void
  CheesePizza::prepare() {
    std::cout << "Preparing " << getName() << std::endl;
    setDough(getIngredientFactory()->createDough());
    setSauce(getIngredientFactory()->createSauce());
    setCheese(getIngredientFactory()->createCheese());
  }

}  // namespace Patterns