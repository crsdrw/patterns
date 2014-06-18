#pragma once

namespace Patterns {

  class Observer;

  class Subject {
  public:
    virtual void registerObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
    virtual void notifyObservers() const = 0;
  };

}