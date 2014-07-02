#pragma once
#include "PatternsLib/Pizza/SimplePizzaFactory.h"
#include "PatternsLib/Pizza/Pizza.h"
#include <memory>

namespace Patterns {

  class PizzaStore {
  private:
    const SimplePizzaFactory* factory_;
  public:
    PizzaStore(const SimplePizzaFactory* factory) : factory_(factory) {}
    std::unique_ptr<Pizza> orderPizza(std::string type) {
      std::unique_ptr<Pizza> pizza = factory_->createPizza(type);
      if (pizza) {
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
      }
      return pizza;
    }
  };

}  // namespace Patterns