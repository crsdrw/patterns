#pragma once
#include "PatternsLib/Pizza/Pizza.h"
#include <iostream>

namespace Patterns {

  class ChicagoStyleCheesePizza : public Pizza {
  public:
    ChicagoStyleCheesePizza() : Pizza("Chicago Style Deep Dish Cheese Pizza", "Extra Thick Crust Dough", "Plum Tomato Sauce") {
      addTopping("Shredded Mozzarella Cheese");
    }

    void cut() override {
      std::cout << "Cutting the pizza into square slices\n";
    }
  };

}  // namespace Patterns