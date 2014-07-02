#include "PatternsLib/Observer/Subject.h"
#include "PatternsLib/Observer/Observer.h"

namespace Patterns {

  Subject::~Subject() { }

  void Subject::registerObserver(Ptr o) {
    observers_.insert(o);
  }
  void Subject::removeObserver(Ptr o) {
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
