#pragma once
#include <string>

namespace Patterns {

  class Veggie {
  public:
    virtual std::string toString() = 0;
    virtual ~Veggie(){}
  };

}  // namespace Patterns