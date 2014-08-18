#include "PatternsConsole/MakePizza.h"
#include "PatternsLib/Pizza/PizzaStoreV0.h"
#include "PatternsLib/Pizza/SimplePizzaFactory.h"
#include "PatternsLib/Pizza/Pizza.h"
#include "PatternsLib/Pizza/PizzaStoreV0.h"
#include "PatternsLib/Pizza/NYPizzaStore.h"
#include "PatternsLib/Pizza/ChicagoPizzaStore.h"
#include "PatternsLib/Pizza/PizzaPrototypeFactory.h"


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
    NYPizzaStore ny_store;
    ChicagoPizzaStore chicago_store;

    auto pizza = ny_store.orderPizza("cheese");
    std::cout << "Ethan ordered a " << pizza->getName() << std::endl;
    std::cout << pizza->toString() << std::endl;

    pizza = chicago_store.orderPizza("cheese");
    std::cout << "Joel ordered a " << pizza->getName() << std::endl;
    std::cout << pizza->toString() << std::endl;

    std::cout << "-- Prototype --\n";
    auto cheese_pizza_prototype = factory.createPizza("cheese");
    auto pepperoni_pizza_prototype = factory.createPizza("pepperoni");
    PizzaPrototypeFactory cheese_pizza_factory(std::move(cheese_pizza_prototype));
    PizzaPrototypeFactory pepperoni_pizza_factory(std::move(pepperoni_pizza_prototype));
    auto test_cheese_pizza = cheese_pizza_factory.makePizza();
    std::cout << "Cheese prototype factory produced " << test_cheese_pizza->getName() << std::endl;
    auto test_pepperoni_pizza = pepperoni_pizza_factory.makePizza();
    std::cout << "Pepperoni prototype factory produced " << test_pepperoni_pizza->getName() << std::endl;
  }
}  // namspace Patterns