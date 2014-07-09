#include "PatternsLib/Builder/VacationBuilder.h"

#include <stdexcept>

namespace Patterns {

  void VacationBuilder::addDay() {
    if (current_day)
      vacation_planner.addDay(*current_day);
    current_day = std::make_unique<VacationDay>();
  }

  VacationPlanner VacationBuilder::getVacationPlanner() {
    if (current_day)
      vacation_planner.addDay(*current_day);
    return vacation_planner;
  }

  void VacationBuilder::addReservation(std::string reservation) {
    if (!current_day)
      throw std::invalid_argument("Can't add a hotel without a day");
    current_day->setDinnerReservation(std::move(reservation));
  }

  void VacationBuilder::addSpecialEvent(std::string name) {
    if (!current_day)
      throw std::invalid_argument("Can't add a hotel without a day");
    current_day->addSpecialEvent(std::move(name));
  }

  void VacationBuilder::addTicket(std::string ticket) {
    if (!current_day)
      throw std::invalid_argument("Can't add a hotel without a day");
    current_day->addTicket(std::move(ticket));
  }

  void VacationBuilder::addHotel(std::string name) {
    if (!current_day)
      throw std::invalid_argument("Can't add a hotel without a day");
    current_day->setHotel(std::move(name));
  }

}  // namespace Patterns