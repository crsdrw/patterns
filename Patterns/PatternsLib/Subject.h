#pragma once
#include <set>
#include <memory>
#include "PatternsLib/Observer.h"

namespace Patterns {

  class Subject {
  private:
    // Choosen std::set because iterators are not invalidated by insertions
    std::set<std::weak_ptr<Observer>, std::owner_less<std::weak_ptr<Observer>>> observers_;
  public:
    void registerObserver(std::shared_ptr<Observer> o);
    void removeObserver(std::shared_ptr<Observer> o);
    void notifyObservers();
    virtual ~Subject();
  };

}