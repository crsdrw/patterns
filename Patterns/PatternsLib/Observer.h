#pragma once
#include <memory>
#include "PatternsLib/Subject.h"

namespace Patterns {

  class Observer : private std::enable_shared_from_this<Observer> {
   public:
     Observer(std::shared_ptr<Subject> subject) { if (subject) subject->registerObserver(enable_shared_from_this); }
    virtual void notify() = 0;
    virtual ~Observer() {};
  };

}