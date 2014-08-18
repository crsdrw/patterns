#include "PatternsLib/Singleton/ThreadSafeSingleton.h"

namespace Patterns {

  std::unique_ptr<ThreadSafeSingleton> ThreadSafeSingleton::instance_;
  std::once_flag ThreadSafeSingleton::once_flag_;

  ThreadSafeSingleton& ThreadSafeSingleton::getInstance() {
    std::call_once(once_flag_, [] {
      instance_.reset(new ThreadSafeSingleton());
    });
    return *instance_.get();
  }

}  // namespace Patterns