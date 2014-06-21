#pragma once
#include <memory>

namespace Patterns {
  class Subject;

  class Observer : std::enable_shared_from_this<Observer> {
   public:
    virtual ~Observer();
    virtual void notify() = 0;
    void observe(std::shared_ptr<Subject> subject);
  };
}