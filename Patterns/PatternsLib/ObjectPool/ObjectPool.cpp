#include "PatternsLib/ObjectPool/ObjectPool.h"

namespace Patterns {

  Resource* ObjectPool::getResource() {
    for (auto& resource : resources_) {
      if (!resource.inUse) {
        resource.init();
        return &resource;
      }
    }
    return nullptr;
  }

}  // namespace Patterns