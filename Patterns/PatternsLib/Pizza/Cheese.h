#pragma once
#include <string>

namespace Patterns {

  class Cheese {
  public:
    virtual std::string toString() const = 0;
    virtual ~Cheese(){}
  };

}  // namespace Patterns