#pragma once
#include <memory>

namespace Patterns {
  class Subject;

  class Observer : private std::enable_shared_from_this<Observer> {
   public:
     Observer(std::shared_ptr<Subject> subject);
    virtual ~Observer();
    virtual void notify() = 0;
  };

}