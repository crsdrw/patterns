#pragma once
#include <string>
#include <memory>
#include <iostream>

#include "PatternsLib/Facade/AudioDevice.h"
#include "PatternsLib/Facade/VideoDevice.h"

namespace Patterns {

  class Amplifier;

  class DvdPlayer : public AudioDevice, public VideoDevice {
  private:
    std::string description_;
    int current_chapter_;
    Amplifier* amplifier_;
    std::string movie_;
  public:
    DvdPlayer(std::string description, Amplifier* amplifier);
    void on() { std::cout << description_ << " on\n"; }
    void off() { std::cout << description_ << " off\n"; }
    void eject() { movie_ = "";  std::cout << description_ << " eject\n"; }
    void stop() { current_chapter_ = 0; std::cout << description_ << " stopped\n"; }
    void pause() { std::cout << description_ << " paused \"" << movie_ << "\"\n"; }
    void play(std::string movie);
    void play(int chapter);
    std::string getDescription() const { return description_; }
  };
}  // namespace Patterns
