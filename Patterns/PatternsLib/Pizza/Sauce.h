#pragma once
#include <string>


namespace Patterns {

  class Sauce {
  public:
    virtual std::string toString() const = 0;
    virtual ~Sauce(){}
  };

}  // namespace Patterns