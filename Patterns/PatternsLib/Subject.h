#pragma once
#include <set>

namespace Patterns {

  class Observer;

  class Subject {
  private:
    // Choosen std::set because iterators are not invalidated by insertions
    std::set<Observer *> observers_;
  public:
    void registerObserver(Observer* o);
    void removeObserver(Observer* o);
    void notifyObservers() const;
  };

}