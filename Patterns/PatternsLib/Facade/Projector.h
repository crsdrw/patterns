#pragma once
#include <memory>
#include <string>
#include <iostream>

namespace Patterns {

  class VideoDevice;

  class Projector {
  private:
    std::string description_;
    VideoDevice* input_;
  public:
    Projector(std::string description) : description_(std::move(description)) {}
    void on() { std::cout << description_ << " on\n"; }
    void off() { std::cout << description_ << " off\n"; }
    void wideScreenMode() { std::cout << description_ << " in widescreen mode (16x9 aspect ratio)\n"; }
    void tvMode() { std::cout << description_ << " in tv mode (4x3 aspect ratio)"; }
    void setInput(VideoDevice* input);
    std::string getDescription() const { return description_; }
  };
}  // namespace Patterns
