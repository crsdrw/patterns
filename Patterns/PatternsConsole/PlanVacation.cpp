#include "PatternsConsole/PlanVacation.h"
#include "PatternsLib/Builder/VacationBuilder.h"
#include "PatternsLib/Builder/TravelAgent.h"
#include <iostream>

namespace {
  using Patterns::VacationPlanner;
  using Patterns::VacationDay;

  void print(const VacationDay& day) {
    std::cout << "Hotel: " << day.getHotel() << std::endl;
    std::cout << "Dinner Reservation: " << day.getDinnerReservation() << std::endl;
    std::cout << "Tickets:\n";
    size_t num_tickets = day.getNumTickets();
    for (size_t i = 0; i != num_tickets; ++i)
      std::cout << "  " << day.getTicket(i) << std::endl;
    std::cout << "Special Events:\n";
    size_t num_events = day.getNumSpecialEvents();
    for (size_t i = 0; i != num_events; ++i)
      std::cout << "  " << day.getSpecialEvent(i) << std::endl;
  }

  void print(const VacationPlanner& planner) {
    size_t num_days = planner.getNumDays();
    for (size_t i = 0; i != num_days; ++i) {
      std::cout << "--- Day " << i + 1 << " ---\n";
     print(planner.getDay(i));
    }
  }
} // namespace

namespace Patterns {
  void planVacation() {
    VacationBuilder builder;
    createVacation(&builder);
    VacationPlanner planner = builder.getVacationPlanner();
    print(planner);
  }
}  // namspace Patterns