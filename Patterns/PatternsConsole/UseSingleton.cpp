#include "PatternsConsole/UseSingleton.h"
#include "PatternsLib/Singleton/Singleton.h"
#include "PatternsLib/Singleton/ThreadSafeSingleton.h"
#include <iostream>
namespace Patterns {
  void useSingleton() {
    auto& s = Singleton::getInstance();
    std::cout << &s << std::endl;
    auto& s2 = Singleton::getInstance();
    std::cout << &s2 << std::endl;
    //auto s = Singleton::getInstance(); // doesn't compile, good
    //s2 = s; // doesn't compile, good
    //Singleton s; // doesn't compile, good
  }

  void useThreadSafeSingleton() {
    auto& s = ThreadSafeSingleton::getInstance();
    std::cout << &s << std::endl;
    auto& s2 = ThreadSafeSingleton::getInstance();
    std::cout << &s2 << std::endl;
    //auto s = ThreadSafeSingleton::getInstance(); // doesn't compile, good
    //s2 = s; // doesn't compile, good
    //ThreadSafeSingleton s; // doesn't compile, good
  }
}  // namespace Patterns