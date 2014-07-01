#pragma once
#include "PatternsLib/Cheese.h"

namespace Patterns {

  class Mozzarella : public Cheese {
  public:
    std::string toString() const override { return "Mozzarella"; }
  };

}  // namespace Patterns