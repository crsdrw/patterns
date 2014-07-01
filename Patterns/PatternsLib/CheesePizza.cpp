#include "PatternsLib/CheesePizza.h"
#include "PatternsLib/Dough.h"
#include "PatternsLib/Sauce.h"
#include "PatternsLib/Cheese.h"
#include "PatternsLib/PizzaIngredientFactory.h"

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