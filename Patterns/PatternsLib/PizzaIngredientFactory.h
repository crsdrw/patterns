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
    virtual std::unique_ptr<Dough> createDough();
    virtual std::unique_ptr<Sauce> createSauce();
    virtual std::unique_ptr<Cheese> createCheese();
    virtual std::unique_ptr<Clam> createClam();
    virtual std::vector<std::unique_ptr<Veggie>> createVeggies();
  };

}  // namespace Patterns