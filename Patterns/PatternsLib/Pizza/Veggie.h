#pragma once
#include <string>

namespace Patterns {

  class Veggie {
  public:
    virtual std::string toString() const = 0;
    virtual ~Veggie(){}
  };

}  // namespace Patterns