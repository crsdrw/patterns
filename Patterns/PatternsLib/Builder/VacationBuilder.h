#pragma once

#include "PatternsLib/Builder/AbstractBuilder.h"
#include "PatternsLib/Builder/VacationPlanner.h"
#include <memory>

namespace Patterns {
  class VacationBuilder : public AbstractBuilder {
  private:
    VacationPlanner vacation_planner;
    std::unique_ptr<VacationDay> current_day;
  public:
    virtual void addDay() override;
    virtual void addHotel(std::string name) override;
    virtual void addReservation(std::string reservation) override;
    virtual void addTicket(std::string name) override;
    virtual void addSpecialEvent(std::string name) override;
    VacationPlanner getVacationPlanner();
  };
}