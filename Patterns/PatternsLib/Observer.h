#pragma once
#include <memory>

namespace Patterns {
  class Observer {
   public:
    virtual ~Observer() {}
    virtual void notify() = 0;
  };

  template<typename O, typename S, typename... Args> std::shared_ptr<O>
  makeObserver(std::shared_ptr<S> subject, Args&&... args) {
    auto observer = std::make_shared<O>(args...);
    observer->setSubject(subject);
    if (subject) subject->registerObserver(observer);
    return observer;
  }
}  // namespace Patterns
