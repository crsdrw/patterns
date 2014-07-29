#include "PatternsConsole/UsePool.h"
#include "PatternsLib/ObjectPool/ObjectPool.h"
#include "PatternsLib/ObjectPool/Resource.h"
#include "PatternsLib/ObjectPool/ResourceE.h"
#include <iostream>
#include <deque>

namespace {

  template<class P>
  void stressTestPool(P& pool) {
    std::deque<decltype(pool.getResource())> in_use;

    for (auto i = 0u; i != 50000; ++i)
      in_use.emplace_back(pool.getResource());

    size_t current = 1;
    size_t previous = 0;
    bool get = true;
    for (auto i = 0u; i != 25; ++i) {
      for (auto j = 0u; j != current; ++j) {
        if (get)
          in_use.emplace_back(pool.getResource());
        else {
          in_use.pop_front();
        }
      }
      auto tmp = current;
      current += previous;
      previous = tmp;
      get = !get;
    }
  }

}  // namespace

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

  void performPool() {
    ObjectPool<ResourceE> object_pool(100000u);
    std::deque<ObjectPool<ResourceE>::Ptr> in_use;

    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cout << "Commencing test..." << std::endl;


    for (int i = 0; i != 10; ++i)
      stressTestPool(object_pool);
  }

}  // namespace Patterns