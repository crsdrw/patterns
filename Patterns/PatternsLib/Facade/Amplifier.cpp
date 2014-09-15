#include "PatternsLib/Facade/Amplifier.h"
#include "PatternsLib/Facade/AudioDevice.h"

namespace Patterns {

  void Amplifier::setInput(std::weak_ptr<AudioDevice> input) {
    input_ = std::move(input);
  }

}  // namespace Patterns
