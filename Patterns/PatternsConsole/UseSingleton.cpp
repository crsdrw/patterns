#include "PatternsConsole/UseSingleton.h"
#include "PatternsLib/Singleton/Singleton.h"
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
}  // namespace Patterns