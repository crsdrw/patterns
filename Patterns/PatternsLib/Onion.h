#pragma once
#include "PatternsLib/Veggie.h"

namespace Patterns {

  class Onion : public Veggie {
  public:
    std::string toString() const override { return "Onion"; }
  };

}  // namespace Patterns