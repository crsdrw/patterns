#pragma once
#include <string>


namespace Patterns {

  class Sauce {
  public:
    std::string toString() = 0;
    virtual ~Sauce(){}
  };

}  // namespace Patterns