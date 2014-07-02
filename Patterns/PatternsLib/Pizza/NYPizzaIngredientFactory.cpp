#include "PatternsLib/Pizza/NYPizzaIngredientFactory.h"
#include "PatternsLib/Pizza/ThinCrustDough.h"
#include "PatternsLib/Pizza/MarinaraSauce.h"
#include "PatternsLib/Pizza/ReggianoCheese.h"
#include "PatternsLib/Pizza/FreshClam.h"
#include "PatternsLib/Pizza/Garlic.h"
#include "PatternsLib/Pizza/Onion.h"

namespace Patterns {

  std::unique_ptr<Dough>
  NYPizzaIngredientFactory::createDough() {
    return std::make_unique<ThinCrustDough>();
  }

  std::unique_ptr<Sauce>
    NYPizzaIngredientFactory::createSauce() {
    return std::make_unique<MarinaraSauce>();
  }

  std::unique_ptr<Cheese>
    NYPizzaIngredientFactory::createCheese() {
    return std::make_unique<ReggianoCheese>();
  }

  std::unique_ptr<Clam>
    NYPizzaIngredientFactory::createClam() {
    return std::make_unique<FreshClam>();
  }

  std::vector<std::unique_ptr<Veggie>>
  NYPizzaIngredientFactory::createVeggies() {
    std::vector<std::unique_ptr<Veggie>> veggies;
    veggies.emplace_back(std::make_unique<Garlic>());
    veggies.emplace_back(std::make_unique<Onion>());
    return veggies;
  }

}  // namespace Patterns
