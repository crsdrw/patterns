#pragma once

#include "PatternsLib/ObjectPool/Resource.h"
#include <vector>
#include <memory>

namespace Patterns {

  template <class T>
  class ObjectPool {
  private:
    
    // Inner class to be the custom deleter for smart pointers to the resource
    // retrieved from the pool.
    template<class T>
    struct Deleter {
      ObjectPool<T>* object_pool_;
      void operator()(T* resource) { object_pool_->freeResource(resource); }
    };
    
    std::vector<T> resources_;  // The object pool itself.
    std::vector<T*> free_list_;  // List of available objects in the pool.

    void freeResource(T*);  // Free a resource from the pool, only called by Deleter.
  public:
    typedef std::unique_ptr<T, Deleter<T>> Ptr;
    ObjectPool(size_t pool_size);
    Ptr getResource();
  };

  template<class T>
  ObjectPool<T>::ObjectPool(size_t pool_size) : free_list_(pool_size), resources_(pool_size) {
    for (auto i = 0u; i != pool_size; ++i)
      free_list_[i] = &resources_[i];
  }

  template <class T> typename ObjectPool<T>::Ptr
  ObjectPool<T>::getResource() {
    if (free_list_.empty())
      return nullptr;
    auto resource = Ptr(free_list_.back(), Deleter<T>{this});
    free_list_.pop_back();
    return resource;
  }

  template <class T> void
  ObjectPool<T>::freeResource(T* resource) {
    resource->clear();
    free_list_.push_back(resource);
  }

}  // namespace Patterns