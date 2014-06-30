#pragma once
#include "PatternsLib/Clam.h"

namespace Patterns {

  class FreshClam : public Clam {
  public:
    std::string toString() override { return "Fresh Clam"; }
  };

}  // namespace Patterns