#pragma once
#include <string>


namespace Patterns {

  class Clam {
  public:
    virtual std::string toString() const = 0;
    virtual ~Clam(){}
  };

}  // namespace Patterns