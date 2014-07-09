#include "PatternsLib/Builder/TravelAgent.h"

namespace Patterns {

  void planVacation(AbstractBuilder* builder) {
    builder->addDay();
    builder->addHotel("Fancy Hotel");
    builder->addTicket("Disney Land");
    builder->addReservation("Fancy restaurant");
    builder->addSpecialEvent("The parade");
  }

}  // namespace