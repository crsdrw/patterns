#include "PatternsLib/Facade/CdPlayer.h"

namespace Patterns {

  CdPlayer::CdPlayer(std::string description, std::weak_ptr<Amplifier> amplifier) : 
    description_(description),
    amplifier_(std::move(amplifier)) {

  }

  void CdPlayer::play(std::string title) {
    title_ = std::move(title);
    current_track_ = 0;
    std::cout << description_ << " playing \"" << title_ << "\"\n";
  }

  void CdPlayer::play(int track) {
    if (title_.empty())
      throw std::invalid_argument(description_ + " can't play track " + std::to_string(track) + ", no cd inserted");

    current_track_ = track;
    std::cout << description_ << " playing track " << current_track_ << std::endl;
  }

}  // namespace Patterns