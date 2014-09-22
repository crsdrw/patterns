#include "PatternsLib/Facade/Projector.h"
#include "PatternsLib/Facade/VideoDevice.h"

namespace Patterns {

  void Projector::setInput(VideoDevice* input) {
    input_ = input;
  }

}  // namespace Patterns