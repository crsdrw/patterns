#pragma once
#include "PatternsLib/Pizza/Sauce.h"

namespace Patterns {

  class PlumTomatoSauce : public Sauce {
  public:
    std::string toString() const override { return "Plum Tomato Sauce"; }
  };

}  // namespace Patterns