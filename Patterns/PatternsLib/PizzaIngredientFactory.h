#pragma once
#include <memory>
#include <vector>

namespace Patterns {
  class Dough;
  class Sauce;
  class Cheese;
  class Clam;
  class Veggie;

  class PizzaIngredientFactory {
  public:
    virtual ~PizzaIngredientFactory() {}
    virtual std::unique_ptr<Dough> createDough() = 0;
    virtual std::unique_ptr<Sauce> createSauce() = 0;
    virtual std::unique_ptr<Cheese> createCheese() = 0;
    virtual std::unique_ptr<Clam> createClam() = 0;
    virtual std::vector<std::unique_ptr<Veggie>> createVeggies() = 0;
  };

}  // namespace Patterns