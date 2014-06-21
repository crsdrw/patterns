#pragma once
#include <set>
#include <memory>

namespace Patterns {
  class Observer;

  class Subject {
   private:
     typedef std::weak_ptr<Observer> WeakPtr;
     typedef std::shared_ptr<Observer> Ptr;

    // Choosen std::set because iterators are not invalidated by insertions
    std::set<WeakPtr, std::owner_less<WeakPtr>> observers_;
   public:
    void registerObserver(Ptr o);
    void removeObserver(Ptr o);
    void notifyObservers();
    virtual ~Subject();
  };
}  // namespace Patterns
