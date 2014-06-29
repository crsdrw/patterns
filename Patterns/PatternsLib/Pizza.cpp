#include "PatternsLib/Pizza.h"
#include <iostream>

namespace Patterns {

  Pizza::Pizza(std::string name) : name_(std::move(name)) {
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
