#pragma once
#include <unordered_set>

namespace Patterns {

  class Observer;

  class Subject {
  private:
    std::unordered_set<Observer *> observers_;
  public:
    void registerObserver(Observer* o);
    void removeObserver(Observer* o);
    void notifyObservers() const;
  };

}