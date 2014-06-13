#pragma once

#include "PatternsLib/FlyBehaviour.h"
#include "PatternsLib/QuackBehaviour.h"
#include <iostream>

namespace Patterns {
  class Duck {
   private: 
    FlyBehaviour::Ptr   fly_behaviour_;
    QuackBehaviour::Ptr quack_behaviour_;
   public:
     Duck(FlyBehaviour::Ptr fly_behaviour, QuackBehaviour::Ptr quack_behaviour)
       : fly_behaviour_(std::move(fly_behaviour))
       , quack_behaviour_(std::move(quack_behaviour)) { }
    virtual void display() const = 0;
    void performFly() { fly_behaviour_->fly(); }
    void performQuack() { quack_behaviour_->quack(); }
    void swim() { std::cout << "All ducks float, even decoys!\n"; }
    void setFlyBehaviour(FlyBehaviour::Ptr fly_behaviour) {
      fly_behaviour_ = std::move(fly_behaviour);
    }
    void setQuackBehaviour(QuackBehaviour::Ptr quack_behaviour) {
      quack_behaviour_ = std::move(quack_behaviour);
    }
  };
}  // namespace Patterns
