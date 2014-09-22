#pragma once

#include "PatternsLib/Facade/AudioDevice.h"

#include <memory>
#include <string>
#include <iostream>

namespace Patterns {

  class Amplifier;

  class CdPlayer : public AudioDevice {
  private:
    std::string description_;
    Amplifier* amplifier_;
    int current_track_;
    std::string title_;
  public:
    CdPlayer(std::string description, Amplifier* amplifier);
    void on() { std::cout << description_ << " on\n"; }
    void off() { std::cout << description_ << " off\n"; }
    void eject() { title_ = "";  std::cout << description_ << " eject\n"; }
    void stop() { current_track_ = 0; std::cout << description_ << " stopped\n";}
    void pause() { std::cout << description_ << " paused \"" << title_ << "\"\n"; }
    std::string getDescription() const { return description_; }
    void play(std::string title);
    void play(int track);
  };

  inline std::ostream& operator<<(std::ostream& out, const CdPlayer& cd) {
    return out << cd.getDescription();
  }

}  // namespace Patterns