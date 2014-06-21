#pragma once
#include <memory>

namespace Patterns {
  class Subject;

  class Observer {
   public:
    virtual ~Observer() {}
    virtual void notify() = 0;
  };

  template<typename O, typename S> std::shared_ptr<O>
  makeObserver(std::shared_ptr<S> subject) {
    auto observer = std::make_shared<O>();
    observer->setSubject(subject);
    if (subject) subject->registerObserver(observer);
    return observer;
  }
}  // namespace Patterns
