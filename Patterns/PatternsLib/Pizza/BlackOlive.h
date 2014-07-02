#pragma once
#include "PatternsLib/Pizza/Veggie.h"

namespace Patterns {

  class BlackOlive : public Veggie {
  public:
    std::string toString() const override { return "Black Olive"; }
  };

}  // namespace Patterns