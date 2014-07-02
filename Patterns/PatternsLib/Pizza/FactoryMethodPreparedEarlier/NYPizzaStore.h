#include "PatternsLib/Pizza/PizzaStore.h"

namespace Patterns {

  class NYPizzaStore : public PizzaStore {
    std::unique_ptr<Pizza> createPizza(std::string item) override;
  };

}  // namespace Patterns