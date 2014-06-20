#include "PatternsLib/Subject.h"
#include "PatternsLib/Observer.h"

namespace Patterns {

  Subject::~Subject() { }

  void Subject::registerObserver(std::shared_ptr<Observer> o) {
    if (o) observers_.insert(o);
  }
  void Subject::removeObserver(std::shared_ptr<Observer> o) {
    observers_.erase(o);
  }
  void Subject::notifyObservers() {
    for (auto iter = observers_.begin(); iter != observers_.end(); ++iter) {
      std::shared_ptr<Observer> observer = iter->lock();
      if (observer)
        observer->notify();
      else
        iter = observers_.erase(iter);
    }

  }

}  // namespace Patterns