#pragma once

#include <memory>
#include <mutex>

namespace Patterns {

  class ThreadSafeSingleton {
   private:
    static std::unique_ptr<ThreadSafeSingleton> instance_;
    static std::once_flag                       once_flag_;
    
    ThreadSafeSingleton() {}

   public:
     static ThreadSafeSingleton& getInstance();
  };

}  // namespace Patterns