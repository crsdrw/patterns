#pragma once
#include <array>

namespace Patterns {

  struct ResourceE {
    int i;
    std::array<char, 100> buf;
    ResourceE() { clear(); }
    void clear() {
      i = 0;
      buf.fill('\0');
    }
  };

}  // namespace Patterns