#pragma once
#include "PatternsLib/Veggie.h"

namespace Patterns {

  class Spinach : public Veggie {
  public:
    std::string toString() const override { return "Spinach"; }
  };

}  // namespace Patterns