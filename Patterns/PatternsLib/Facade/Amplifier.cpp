#include "PatternsLib/Facade/Amplifier.h"

namespace Patterns {

  void Amplifier::setTuner(std::weak_ptr<Tuner> tuner) {
    tuner_ = std::move(tuner);
  }

  void Amplifier::setDvd(std::weak_ptr<DvdPlayer> dvd) {
    dvd_ = std::move(dvd);
  }

  void Amplifier::setCd(std::weak_ptr<CdPlayer> cd) {
    cd_ = std::move(cd);
  }

}  // namespace Patterns
