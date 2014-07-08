#pragma once

#include "PatternsLib/Builder/AbstractBuilder.h"
#include "PatternsLib/Builder/VacationPlanner.h"
#include <memory>

namespace Patterns {
  class VacationBuilder : public AbstractBuilder {
  private:
    VacationPlanner vacation_planner;
  public:
    virtual void addDay();
    virtual void addHotel(std::string name);
    virtual void addReservation(std::string restauraunt);
    virtual void addTickets(std::string name);
    virtual void addSpecialEvent(std::string name);
    VacationPlanner getVacationPlanner() { return vacation_planner; }
  };
}