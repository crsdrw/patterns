#pragma once
#include "PatternsLib/Clam.h"

namespace Patterns {

  class FrozenClam : public Clam {
  public:
    std::string toString() override { return "Frozen Clam"; }
  };

}  // namespace Patterns