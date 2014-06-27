#include "PatternsLib/Pizza.h"
#include <iostream>

namespace Patterns {

  void Pizza::prepare() {
    std::cout << "Preparing " << name_ << std::endl;
    std::cout << "Tossing dough....\n";
    std::cout << "Adding sauce...\n";
    std::cout << "Adding toppings:\n";
    for (auto& topping : toppings_)
      std::cout << "    " << topping << std::endl;
  }

  void Pizza::bake() {
    std::cout << "Bake for 25 minutes at 350\n";
  }

  void Pizza::cut() {
    std::cout << "Cutting the pizza into diagonal slices\n";
  }

  void Pizza::box() {
    std::cout << "Place pizza in official PizzaStore box\n";
  }
}  // namespace Patterns
