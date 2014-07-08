#pragma once

#include <string>
#include <vector>

namespace Patterns {

  class VacationDay {
  private:
    std::string hotel_;
    std::string dinner_reservation_;
    std::vector<std::string> tickets_;
    std::vector<std::string> special_events_;
  public:
    void setHotel(std::string hotel) { hotel_ = hotel; }
    void setDinnerReservation(std::string reservation) { dinner_reservation_ = reservation; }
    void addTicket(std::string name) { tickets_.emplace_back(name); }
    void addSpecialEvent(std::string name) { special_events_.emplace_back(name); }
  };

}  // namsepace Patterns