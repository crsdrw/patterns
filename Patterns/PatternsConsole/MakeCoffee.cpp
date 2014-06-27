#include "PatternsConsole/MakeCoffee.h"
#include "PatternsLib/Espresso.h"
#include "PatternsLib/DarkRoast.h"
#include "PatternsLib/Mocha.h"
#include "PatternsLib/Whip.h"
#include "PatternsLib/Beverage.h"

#include <memory>
#include <iostream>

namespace Patterns {

  void makeCoffee() {
    auto beverage = make_beverage<Espresso>();
    std::cout << beverage->getDescription() << " $" << beverage->cost() << std::endl;

    auto beverage2 = make_beverage<DarkRoast>();
    beverage2 = make_beverage<Mocha>(std::move(beverage2));
    beverage2 = make_beverage<Mocha>(std::move(beverage2));
    beverage2 = make_beverage<Whip>(std::move(beverage2));
    std::cout << beverage2->getDescription() << " $" << beverage2->cost() << std::endl;
  }
}  // namespace Patterns
