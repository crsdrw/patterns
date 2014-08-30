#pragma once
#include <memory>
#include <string>
#include <iostream>
#include <stdexcept>

namespace Patterns {

  class Amplifier;

  class CdPlayer {
  private:
    std::string description_;
    std::weak_ptr<Amplifier> amplifier_;
    int current_track_;
    std::string title_;
  public:
    CdPlayer(std::string description, std::weak_ptr<Amplifier> amplifier);
    void on() { std::cout << description_ << " on\n"; }
    void off() { std::cout << description_ << " off\n"; }
    void eject() { title_ = "";  std::cout << description_ << " eject\n"; }
    void stop() { current_track_ = 0; std::cout << description_ << " stopped\n";}
    void pause() { std::cout << description_ << " paused \"" << title_ << "\"\n"; }
    std::string getDescription() { return description_; }
    void play(std::string title);
    void play(int track);
  };

  //std::ostream& operator<<(std::ostream& out, const CdPlayer& cd) {
  //  return out << cd.getDescription();
  //}

}  // namespace Patterns