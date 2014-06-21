#include "PatternsLib/Subject.h"
#include "PatternsLib/Observer.h"

namespace Patterns {

  Subject::~Subject() { }

  void Subject::registerObserver(std::shared_ptr<Observer> o) {
    observers_.insert(o);
  }
  void Subject::removeObserver(std::shared_ptr<Observer> o) {
    observers_.erase(o);
  }
  void Subject::notifyObservers() {
    auto iter = observers_.begin();
    while (iter != observers_.end()) {
      auto observer = iter->lock();
      if (observer) {
        observer->notify();
        ++iter;
      } else {
        iter = observers_.erase(iter);
      }
    }
  }
}  // namespace Patterns
