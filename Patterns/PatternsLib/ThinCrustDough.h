#pragma once
#include "PatternsLib/Dough.h"

namespace Patterns {

  class ThinCrustDough : public Dough {
  public:
    std::string toString() const override { return "Thin Crust Dough"; }
  };

}  // namespace Patterns