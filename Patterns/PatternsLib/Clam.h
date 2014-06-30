#pragma once
#include <string>


namespace Patterns {

  class Clam {
  public:
    virtual std::string toString() = 0;
    virtual ~Clam(){}
  };

}  // namespace Patterns