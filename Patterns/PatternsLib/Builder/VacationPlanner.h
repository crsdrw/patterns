#pragma once
#include <vector>
#include "PatternsLib/Builder/VacationDay.h"

namespace Patterns {
  class VacationPlanner {
  private:
    std::vector<VacationDay> vacation_days;
  public:
    void addDay(VacationDay vacation_day) { vacation_days.emplace_back(vacation_day); }
    size_t getNumDays() const { return vacation_days.size(); }
    const VacationDay& getDay(size_t num) const { return vacation_days.at(num); }
  };
}