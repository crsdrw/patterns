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
    std::string getHotel() const { return hotel_; }
    std::string getDinnerReservation() const { return dinner_reservation_; }
    size_t getNumTickets()  const { return tickets_.size(); }
    size_t getNumSpecialEvents()  const { return special_events_.size(); }
    std::string getTicket(size_t ticket_number)  const { return tickets_.at(ticket_number); }
    std::string getSpecialEvent(size_t event_number)  const { return special_events_.at(event_number); }
  };

}  // namsepace Patterns