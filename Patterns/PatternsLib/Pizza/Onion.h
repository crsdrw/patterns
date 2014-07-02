#pragma once
#include "PatternsLib/Pizza/Veggie.h"

namespace Patterns {

  class Onion : public Veggie {
  public:
    std::string toString() const override { return "Onion"; }
  };

}  // namespace Patterns