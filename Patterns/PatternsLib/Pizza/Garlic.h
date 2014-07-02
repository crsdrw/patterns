#pragma once
#include "PatternsLib/Pizza/Veggie.h"

namespace Patterns {

  class Garlic : public Veggie {
  public:
    std::string toString() const override { return "Garlic"; }
  };

}  // namespace Patterns