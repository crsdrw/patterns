#pragma once
#include <string>
#include <memory>
#include <iostream>

namespace Patterns {

  class Tuner;
  class DvdPlayer;
  class CdPlayer;

  class Amplifier {
  private:
    std::string description_;
    std::weak_ptr<Tuner> tuner_;
    std::weak_ptr<DvdPlayer> dvd_;
    std::weak_ptr<CdPlayer> cd_;
  public:
    Amplifier(std::string description) : description_(description) {}
    void on() { std::cout << description_ << " on\n"; }
    void off() { std::cout << description_ << " off\n"; }
    void setStereoSound() { std::cout << description_ << " stereo mode on\n"; }
    void setSurroundSound() { std::cout << description_ << " surround sound on (5 speakers, 1 subwoofer)\n"; }
    void setTuner(std::weak_ptr<Tuner> tuner);
    void setDvd(std::weak_ptr<DvdPlayer> dvd);
    void setCd(std::weak_ptr<CdPlayer> cd);
    std::string getDescription() const { return description_; }
  };

  std::ofstream& operator<<(std::ofstream& out, const Amplifier& amplifier) {
    return out << amplifier.getDescription();
  }

}  // namespace Patterns