#pragma once
#include "PatternsLib/Pizza/Clam.h"

namespace Patterns {

  class FreshClam : public Clam {
  public:
    std::string toString() const override { return "Fresh Clam"; }
  };

}  // namespace Patterns