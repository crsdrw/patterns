#pragma once

namespace Patterns {
  class Singleton {
   private:
    Singleton() {}
   public:
    static Singleton& getInstance() {
      static Singleton instance;
      return instance;
    }
    Singleton(const Singleton&) = delete;
    void operator=(const Singleton&) = delete;
  };
}  // namespace Patterns