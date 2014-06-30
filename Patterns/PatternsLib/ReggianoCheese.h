#pragma once
#include "PatternsLib/Cheese.h"

namespace Patterns {

  class ReggianoCheese : public Cheese {
  public:
    std::string toString() override { return "Reggiano"; }
  };

}  // namespace Patterns