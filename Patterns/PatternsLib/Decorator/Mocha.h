#pragma once

#include "PatternsLib/Decorator/CondimentDecorator.h"
#include <memory>

namespace Patterns {

  class Mocha : public CondimentDecorator {
  private:
    std::unique_ptr<Beverage> beverage_;
  public:
    Mocha(std::unique_ptr<Beverage> beverage) : beverage_(std::move(beverage)) {}
    std::string getDescription() const override { return beverage_->getDescription() + ", Mocha"; }
    double cost() const override { return 0.20 + beverage_->cost();  }
  };
}