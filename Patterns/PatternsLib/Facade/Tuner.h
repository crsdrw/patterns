#pragma once
#include <memory>
#include <string>
#include <iostream>

#include "PatternsLib/Facade/AudioDevice.h"


namespace Patterns {

  class Amplifier;

  class Tuner : public AudioDevice {
  private:
    std::string description_;
    Amplifier* amplifier_;
    double frequency_;
  public:
    Tuner(std::string description, Amplifier* amplifier);
    void on() { std::cout << description_ << " on\n"; }
    void off() { std::cout << description_ << " off\n"; }
    void setFrequency(double frequency); 
    void setAm() { std::cout << description_ << " setting AM mode\n"; }
    void setFm() { std::cout << description_ << " setting FM mode\n"; }
    std::string getDescription() const { return description_; }
    void play(std::string title);
    void play(int track);
  };
}  // namespace Patterns
