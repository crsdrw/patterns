#pragma once

#include "PatternsLib/ObjectPool/Resource.h"
#include <vector>
#include <deque>
#include <memory>

namespace Patterns {

  template<class T> class ObjectPool;

  template<class T>
  struct ObjectPoolDeleter {
    ObjectPool<T>* object_pool_;
    void operator()(T* resource);
  };


  template <class T>
  class ObjectPool {
    friend struct ObjectPoolDeleter < T > ;
  private:
    std::vector<T> resources_;
    std::deque<T*> free_list_;
    void freeResource(T*);
  public:
    ObjectPool(size_t pool_size);
    std::unique_ptr<T, ObjectPoolDeleter<T>> getResource();
  };

  template<class T> void
  ObjectPoolDeleter<T>::operator()(T* resource) {
    object_pool_->freeResource(resource);
  }

  template<class T>
  ObjectPool<T>::ObjectPool(size_t pool_size) : free_list_(pool_size), resources_(pool_size) {
    for (auto i = 0u; i != pool_size; ++i) {
      free_list_[i] = &resources_[i];
    }
  }

  template <class T> std::unique_ptr<T, ObjectPoolDeleter<T>>
  ObjectPool<T>::getResource() {
    if (free_list_.empty())
      return nullptr;
    T* ret = free_list_.back();
    free_list_.pop_back();
    return std::unique_ptr<T, ObjectPoolDeleter<T>>(ret, ObjectPoolDeleter < T > {this});
  }

  template <class T> void
  ObjectPool<T>::freeResource(T* resource) {
    resource->free();
    free_list_.push_back(resource);
  }

}  // namespace Patterns