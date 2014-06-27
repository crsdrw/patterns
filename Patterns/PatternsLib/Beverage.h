#pragma once
#include <string>
#include <memory>

namespace Patterns {

  class Beverage {
   private:
    std::string description_;
   public:
    Beverage() : description_("Unknown Beverage") {}
    Beverage(std::string description) : description_(std::move(description)) {}
    virtual ~Beverage() {}
    virtual std::string getDescription() const { return description_; }
    virtual double cost() const = 0;
  };

  template<typename B, typename... Args>
  std::unique_ptr<Patterns::Beverage> make_beverage(Args&&... args) {
    return std::make_unique<B>(std::forward<Args>(args)...);
  }

}  // namespace Patterns
