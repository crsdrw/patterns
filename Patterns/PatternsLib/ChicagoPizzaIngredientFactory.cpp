#include "PatternsLib/ChicagoPizzaIngredientFactory.h"
#include "PatternsLib/ThickCrustDough.h"
#include "PatternsLib/PlumTomatoSauce.h"
#include "PatternsLib/Mozzarella.h"
#include "PatternsLib/FrozenClam.h"
#include "PatternsLib/BlackOlive.h"
#include "PatternsLib/Spinach.h"
#include "PatternsLib/Veggie.h"

namespace Patterns {

  std::unique_ptr<Dough>
    ChicagoPizzaIngredientFactory::createDough() {
    return std::make_unique<ThickCrustDough>();
  }

  std::unique_ptr<Sauce>
    ChicagoPizzaIngredientFactory::createSauce() {
    return std::make_unique<PlumTomatoSauce>();
  }

  std::unique_ptr<Cheese>
    ChicagoPizzaIngredientFactory::createCheese() {
    return std::make_unique<Mozzarella>();
  }

  std::unique_ptr<Clam>
    ChicagoPizzaIngredientFactory::createClam() {
    return std::make_unique<FrozenClam>();
  }

  std::vector<std::unique_ptr<Veggie>>
  ChicagoPizzaIngredientFactory::createVeggies() {
    std::vector<std::unique_ptr<Veggie>> veggies;
    veggies.emplace_back(std::make_unique<BlackOlive>());
    veggies.emplace_back(std::make_unique<Spinach>());
    return veggies;
  }
}  // namespace Patterns
