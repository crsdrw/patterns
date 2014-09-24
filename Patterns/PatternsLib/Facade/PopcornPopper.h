#pragma once
#include <string>
#include <iostream>

namespace Patterns {
  class PopcornPopper {
  private:
    std::string description_;
  public:
    PopcornPopper(std::string description) : description_(std::move(description)) {}
    std::string getDescription() const { return description_; }
    void on() { std::cout << description_ << " on\n"; }
    void off() { std::cout << description_ << " off\n"; }
    void pop() { std::cout << description_ << " popping popcorn!\n"; }
  };
}  // namespace Patterns
