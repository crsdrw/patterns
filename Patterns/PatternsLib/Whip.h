#pragma once

#include "PatternsLib/CondimentDecorator.h"
#include <memory>

namespace Patterns {

  class Whip : public CondimentDecorator {
  private:
    std::unique_ptr<Beverage> beverage_;
  public:
    Whip(std::unique_ptr<Beverage> beverage) : beverage_(std::move(beverage)) {}
    std::string getDescription() const override { return beverage_->getDescription() + ", Whip"; }
    double cost() const override { return 0.10 + beverage_->cost(); }
  };
}