#include "PatternsLib/Builder/TravelAgent.h"

namespace Patterns {

  void createVacation(AbstractBuilder* builder) {
    builder->addDay();
    builder->addHotel("Fancy Hotel");
    builder->addTicket("Disney Land");
    builder->addReservation("Fancy restaurant");
    builder->addSpecialEvent("The parade");

    builder->addDay();
    builder->addHotel("Cheap Hotel");
    builder->addTicket("The Zoo");
    builder->addReservation("Pizza Hut");
    builder->addTicket("The Ballet");
  }

}  // namespace