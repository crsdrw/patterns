#include "PatternsConsole/UsePool.h"
#include "PatternsLib/ObjectPool/ObjectPool.h"
#include "PatternsLib/ObjectPool/Resource.h"
#include <iostream>

namespace Patterns {

  void usePool() {

    ObjectPool<Resource> object_pool(100u);
    {
      auto r1 = object_pool.getResource();
      r1->init();
      std::cout << "R1 in use " << r1->inUse() << std::endl;
      auto r2 = object_pool.getResource();
      std::cout << "R2 in use " << r2->inUse() << std::endl;
    }
    auto r3 = object_pool.getResource();
    std::cout << "R3 in use " << r3->inUse() << std::endl;

  }
}  // namespace Patterns