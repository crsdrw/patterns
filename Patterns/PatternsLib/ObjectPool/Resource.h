#pragma once

namespace Patterns {

  class Resource {
  private:
    bool in_use_{ false };
  public:
    bool inUse() { return in_use_; }
    void init() { in_use_ = true; }
    void clear() { in_use_ = false; }
  };

}  // namespace Patterns