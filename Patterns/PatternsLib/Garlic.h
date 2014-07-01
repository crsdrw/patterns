#pragma once
#include "PatternsLib/Veggie.h"

namespace Patterns {

  class Garlic : public Veggie {
  public:
    std::string toString() const override { return "Garlic"; }
  };

}  // namespace Patterns