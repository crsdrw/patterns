#pragma once
#include "PatternsLib/Cheese.h"

namespace Patterns {

  class Mozzarella : public Cheese {
  public:
    std::string toString() override { return "Mozzarella"; }
  };

}  // namespace Patterns