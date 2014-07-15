#pragma once
#include <array>
#include "PatternsLib/ObjectPool/Resource.h"

namespace Patterns {

  template <class T>
  class ObjectPool {
  private:
    static constexpr int POOL_SIZE = 100;
    std::array<T, POOL_SIZE> resources_;

  public:
    T* getResource();
  };

  template <class T> T*
  ObjectPool<T>::getResource() {
    for (auto& resource : resources_) {
      if (!resource.inUse) {
        resource.init();
        return &resource;
      }
    }
  }

  template <class T> void
  ObjectPool<T>::freeResource(T* resource) {

  }

}  // namespace Patterns