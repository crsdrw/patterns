#include "PatternsLib/Observer.h"
#include "PatternsLib/Subject.h"

namespace Patterns {
  Observer::~Observer() {}

  void Observer::observe(std::shared_ptr<Subject> subject) {
    if (subject)
      subject->registerObserver(shared_from_this());
  }
}  // namespace Patterns