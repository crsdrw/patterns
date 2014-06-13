#pragma once

#include <memory>

namespace Patterns {
  class FlyBehaviour {
   public:
    typedef std::unique_ptr<FlyBehaviour> Ptr;
    virtual void fly() = 0;
    virtual ~FlyBehaviour() {}
  };
}  // namespace Patterns
