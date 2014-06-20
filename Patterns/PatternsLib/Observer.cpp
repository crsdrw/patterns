#include "PatternsLib/Observer.h"
#include "PatternsLib/Subject.h"

namespace Patterns {
  Observer::Observer(std::shared_ptr<Subject> subject) {
    if (subject)
      subject->registerObserver(shared_from_this());
  }
  Observer::~Observer() {}
}