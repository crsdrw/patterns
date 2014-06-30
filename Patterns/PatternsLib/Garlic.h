#pragma once
#include "PatternsLib/Veggie.h"

namespace Patterns {

  class Garlic : public Veggie {
  public:
    std::string toString() override { return "Garlic"; }
  };

}  // namespace Patterns