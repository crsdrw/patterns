#pragma once
#include <vector>
#include "PatternsLib/Builder/VacationDay.h"

namespace Patterns {
  class VacationPlanner {
  private:
    std::vector<VacationDay> vacation_days;
  public:
    void addDay(VacationDay vacation_day) { vacation_days.emplace_back(vacation_day); }
  };
}