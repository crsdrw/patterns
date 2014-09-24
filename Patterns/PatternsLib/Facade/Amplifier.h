#pragma once
#include <string>
#include <memory>
#include <iostream>

namespace Patterns {

  class AudioDevice;

  class Amplifier {
  private:
    std::string description_;
    AudioDevice* input_;
  public:
    Amplifier(std::string description) : description_(description) {}
    void on() { std::cout << description_ << " on\n"; }
    void off() { std::cout << description_ << " off\n"; }
    void setVolume(int level) { std::cout << description_ << " setting volume to " << level << std::endl; }
    void setStereoSound() { std::cout << description_ << " stereo mode on\n"; }
    void setSurroundSound() { std::cout << description_ << " surround sound on (5 speakers, 1 subwoofer)\n"; }
    void setInput(AudioDevice* input);
    std::string getDescription() const { return description_; }
  };
}  // namespace Patterns
