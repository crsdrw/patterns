#pragma once
#include <string>

namespace Patterns {

  class Cheese {
  public:
    virtual std::string toString() = 0;
    virtual ~Cheese(){}
  };

}  // namespace Patterns