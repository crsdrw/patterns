#pragma once
#include "PatternsLib/Pizza.h"
#include <iostream>

namespace Patterns {

  class ChicagoStylePepperoniPizza : public Pizza {
  public:
    ChicagoStylePepperoniPizza() : Pizza("Chicago Style Deep Dish Pepperoni Pizza", "Extra Thick Crust Dough", "Plum Tomato Sauce") {
      addTopping("Thickly Sliced Pepperoni");
    }

    void cut() override {
      std::cout << "Cutting the pizza into square slices\n";
    }
  };

}  // namespace Patterns