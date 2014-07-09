#pragma once

#include <string>

namespace Patterns {

  class AbstractBuilder {
  protected:
   ~AbstractBuilder() {}
  public:
    virtual void addDay() = 0;
    virtual void addHotel(std::string name) = 0;
    virtual void addReservation(std::string reservation) = 0;
    virtual void addTicket(std::string name) = 0;
    virtual void addSpecialEvent(std::string name) = 0;
  };

}  // namespace Patterns