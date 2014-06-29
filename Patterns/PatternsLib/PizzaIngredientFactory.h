#pragma once
#include <memory>
#include <vector>

namespace Patterns {
  class Dough;
  class Sauce;
  class Cheese;
  class Pepperoni;
  class Veggie;

  class PizzaIngredientFactory {
  public:
    typedef std::vector<std::unique_ptr<Veggie>> Veggies;
    std::unique_ptr<Dough> createDough();
    std::unique_ptr<Sauce> createSauce();
    std::unique_ptr<Cheese> createCheese();
    Veggies createVeggies();
    std::unique_ptr<Pepperoni> createPepperoni();
  };

}  // namespace Patterns