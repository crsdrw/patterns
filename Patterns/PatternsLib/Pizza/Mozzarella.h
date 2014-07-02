#pragma once
#include "PatternsLib/Pizza/Cheese.h"

namespace Patterns {

  class Mozzarella : public Cheese {
  public:
    std::string toString() const override { return "Mozzarella"; }
  };

}  // namespace Patterns