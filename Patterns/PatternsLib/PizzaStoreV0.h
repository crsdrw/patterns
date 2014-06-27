#pragma once
#include "PatternsLib/SimplePizzaFactory.h"
#include "PatternsLib/Pizza.h"
#include <memory>

namespace Patterns {

  class PizzaStoreV0 {
  private:
    const SimplePizzaFactory* factory_;
  public:
    PizzaStoreV0(const SimplePizzaFactory* factory) : factory_(factory) {}
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