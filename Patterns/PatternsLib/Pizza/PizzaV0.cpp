#include "PatternsLib/Pizza/PizzaV0.h"
#include <iostream>

namespace Patterns {

  void PizzaV0::prepare() {
    std::cout << "Preparing " << name_ << std::endl;
    std::cout << "Tossing dough....\n";
    std::cout << "Adding sauce...\n";
    std::cout << "Adding toppings:\n";
    for (auto& topping : toppings_)
      std::cout << "    " << topping << std::endl;
  }

  void PizzaV0::bake() {
    std::cout << "Bake for 25 minutes at 350\n";
  }

  void PizzaV0::cut() {
    std::cout << "Cutting the pizza into diagonal slices\n";
  }

  void PizzaV0::box() {
    std::cout << "Place pizza in official PizzaStore box\n";
  }

  std::unique_ptr<PizzaV0> PizzaV0::clone() const {
    return std::make_unique<PizzaV0>(*this);
  }

}  // namespace Patterns
