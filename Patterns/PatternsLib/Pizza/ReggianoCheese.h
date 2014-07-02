#pragma once
#include "PatternsLib/Pizza/Cheese.h"

namespace Patterns {

  class ReggianoCheese : public Cheese {
  public:
    std::string toString() const override { return "Reggiano"; }
  };

}  // namespace Patterns