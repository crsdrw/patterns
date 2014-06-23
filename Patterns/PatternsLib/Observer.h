#pragma once

namespace Patterns {
  class Subject;

  class Observer {
   protected:
    ~Observer();
   public:
    Observer(Subject* subject);
    virtual void notify() = 0;
  };

}