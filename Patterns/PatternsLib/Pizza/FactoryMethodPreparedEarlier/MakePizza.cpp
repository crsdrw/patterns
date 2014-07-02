#include "PatternsConsole/MakePizza.h"
#include "PatternsLib/Pizza/PizzaStoreV0.h"
#include "PatternsLib/Pizza/SimplePizzaFactory.h"
#include "PatternsLib/Pizza/Pizza.h"
#include "PatternsLib/Pizza/PizzaStoreV0.h"
#include "PatternsLib/Pizza/NYPizzaStore.h"
#include "PatternsLib/Pizza/ChicagoPizzaStore.h"

#include <iostream>
#include <memory>

namespace Patterns {
  void makePizza() {

    std::cout << "-- Simple Factory --\n";
    SimplePizzaFactory factory;
    PizzaStoreV0 pizza_store(&factory);
    auto pizza1 = pizza_store.orderPizza("cheese");
    auto pizza2 = pizza_store.orderPizza("pepperoni");

    std::cout << "-- Factory Method --\n";
    auto ny_store = NYPizzaStore{};
    auto chicago_store = ChicagoPizzaStore{};

    auto pizza = ny_store.orderPizza("cheese");
    std::cout << "Ethan ordered a " << pizza->getName() << std::endl;

    pizza = chicago_store.orderPizza("cheese");
    std::cout << "Joel ordered a " << pizza->getName() << std::endl;
  }
}  // namspace Patterns