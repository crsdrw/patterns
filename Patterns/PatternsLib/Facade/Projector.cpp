#include "PatternsLib/Facade/Projector.h"
#include "PatternsLib/Facade/VideoDevice.h"

namespace Patterns {

  void Projector::setInput(std::weak_ptr<VideoDevice> input) {
    input_ = std::move(input);
  }

}  // namespace Patterns