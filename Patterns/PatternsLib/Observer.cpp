#include "PatternsLib/Observer.h"
#include "PatternsLib/Subject.h"

namespace Patterns {
  Observer::~Observer() {
  
  }

  Observer::Observer(Subject* subject) {
    subject->registerObserver(this);
  }
}