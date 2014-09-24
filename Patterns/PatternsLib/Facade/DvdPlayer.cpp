#include "PatternsLib/Facade/DvdPlayer.h"
#include "PatternsLib/Facade/Amplifier.h"

#include <stdexcept>

namespace Patterns {

  DvdPlayer::DvdPlayer(std::string description, Amplifier* amplifier) :
    description_(description),
    amplifier_(amplifier) {
  }

  void DvdPlayer::play(std::string movie) {
    movie_ = std::move(movie);
    current_chapter_ = 0;
    std::cout << description_ << " playing \"" << movie_ << "\"\n";
  }

  void DvdPlayer::play(int track) {
    if (movie_.empty())
      throw std::invalid_argument(description_ + " can't play movie " + std::to_string(track) + ", no disk inserted");

    current_chapter_ = track;
    std::cout << description_ << " playing chapter " << current_chapter_ << std::endl;
  }

}  // namespace Patterns
