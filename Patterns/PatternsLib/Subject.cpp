#include "PatternsLib/Subject.h"
#include "PatternsLib/Observer.h"

namespace Patterns {

  void Subject::registerObserver(Observer* o) {
    observers_.insert(o);
  }
  void Subject::removeObserver(Observer* o) {
    observers_.erase(o);
  }
  void Subject::notifyObservers() const {
    for (auto observer : observers_)
      if (observer) observer->notify();
  }

}  // namespace Patterns