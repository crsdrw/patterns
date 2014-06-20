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
  void Subject::notifyObservers() const {
    for (auto& o : observers_) {
      std::shared_ptr<Observer> observer = o.lock();
      if (observer) 
        observer->notify();
    }
  }

}  // namespace Patterns