#pragma once
#include "PatternsLib/Sauce.h"

namespace Patterns {

  class MarinaraSauce : public Sauce {
  public:
    std::string toString() override { return "Marinara Sauce"; }
  };

}  // namespace Patterns