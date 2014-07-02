#pragma once
#include "PatternsLib/Pizza/Clam.h"

namespace Patterns {

  class FrozenClam : public Clam {
  public:
    std::string toString() const override { return "Frozen Clam"; }
  };

}  // namespace Patterns