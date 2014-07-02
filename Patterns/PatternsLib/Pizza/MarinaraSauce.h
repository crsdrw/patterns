#pragma once
#include "PatternsLib/Pizza/Sauce.h"

namespace Patterns {

  class MarinaraSauce : public Sauce {
  public:
    std::string toString() const override { return "Marinara Sauce"; }
  };

}  // namespace Patterns