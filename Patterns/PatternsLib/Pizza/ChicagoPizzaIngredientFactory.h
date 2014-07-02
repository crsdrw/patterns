#pragma once
#include "PatternsLib/Pizza/PizzaIngredientFactory.h"


namespace Patterns {

  class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory {
  public:
    std::unique_ptr<Dough> createDough() override;
    std::unique_ptr<Sauce> createSauce() override;
    std::unique_ptr<Cheese> createCheese() override;
    std::unique_ptr<Clam> createClam() override;
    std::vector<std::unique_ptr<Veggie>> createVeggies() override;
  };

}  // namespace Patterns