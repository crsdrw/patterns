#pragma once

#include <memory>

namespace Patterns {
  class QuackBehaviour {
   public:
    typedef std::unique_ptr<QuackBehaviour> Ptr;
    virtual void quack() = 0;
    virtual ~QuackBehaviour() {}
  };
}  // namespace Patterns
