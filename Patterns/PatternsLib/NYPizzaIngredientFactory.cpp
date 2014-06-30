#include "PatternsLib/NYPizzaIngredientFactory.h"
#include "PatternsLib/ThinCrustDough.h"
#include "PatternsLib/MarinaraSauce.h"
#include "PatternsLib/ReggianoCheese.h"
#include "PatternsLib/FreshClam.h"
#include "PatternsLib/Garlic.h"
#include "PatternsLib/Onion.h"

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
    return std::vector<std::unique_ptr<Veggie>>{ std::make_unique<Garlic>(), std::make_unique<Onion>() };
  }

}  // namespace Patterns
