#include "PatternsLib/Facade/Amplifier.h"
#include "PatternsLib/Facade/AudioDevice.h"

namespace Patterns {

  void Amplifier::setInput(AudioDevice* input) {
    input_ = input;
  }

}  // namespace Patterns
