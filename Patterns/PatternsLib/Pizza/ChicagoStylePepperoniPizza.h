#pragma once
#include "PatternsLib/Pizza/Pizza.h"
#include <iostream>

namespace Patterns {

  class ChicagoStylePepperoniPizza : public Pizza {
  public:
    ChicagoStylePepperoniPizza() : Pizza("Chicago Style Deep Dish Pepperoni Pizza", "Extra Thick Crust Dough", "Plum Tomato Sauce") {
      addTopping("Black Olives");
      addTopping("Spinach");
      addTopping("Eggplant");
      addTopping("Sliced Pepperoni");
    }

    void cut() override {
      std::cout << "Cutting the pizza into square slices\n";
    }
  };

}  // namespace Patterns