#pragma once
#include <string>
#include <iostream>

namespace Patterns {
  class TheaterLights {
  private:
    std::string description_;
  public:
    TheaterLights(std::string description) : description_(std::move(description)) {}
    std::string getDescription() const { return description_; }
    void on() { std::cout << description_ << " on\n"; }
    void off() { std::cout << description_ << " off\n"; }
    void dim(int level) { std::cout << description_ << " dimming to " << level << "%\n"; }
  };
}
