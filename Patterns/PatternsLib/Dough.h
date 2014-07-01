#pragma once
#include <string>


namespace Patterns {

  class Dough {
  public:
    virtual std::string toString() const = 0;
    virtual ~Dough(){}
  };

}  // namespace Patterns