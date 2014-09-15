#pragma once
#include <string>
#include <iostream>

namespace Patterns {
  class Screen {
  private:
    std::string description_;
  public:
    Screen(std::string description) : description_(std::move(description)) {}
    std::string getDescription() const { return description_; }
    void up() { std::cout << description_ << " up\n"; }
    void down() { std::cout << description_ << " down\n"; }
  };

  inline std::ostream& operator<<(std::ostream& out, const Screen& screen) {
    return out << screen.getDescription();
  }
}