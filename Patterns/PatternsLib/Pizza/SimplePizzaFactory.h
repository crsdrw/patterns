#pragma once
#include "PatternsLib/Pizza/Pizza.h"
#include <memory>
#include <string>

namespace Patterns {

  std::unique_ptr<Pizza> createPizza(const std::string& type);

}  // namespace Patterns