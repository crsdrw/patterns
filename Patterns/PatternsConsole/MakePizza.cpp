#include "PatternsConsole/MakePizza.h"
#include "PatternsLib/PizzaStoreV0.h"
#include "PatternsLib/SimplePizzaFactory.h"
#include "PatternsLib/Pizza.h"
#include "PatternsLib/PizzaStoreV0.h"
#include "PatternsLib/NYPizzaStore.h"
#include "PatternsLib/ChicagoPizzaStore.h"

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
    std::cout << pizza->toString() << std::endl;

    pizza = chicago_store.orderPizza("cheese");
    std::cout << "Joel ordered a " << pizza->getName() << std::endl;
    std::cout << pizza->toString() << std::endl;
  }
}  // namspace Patterns