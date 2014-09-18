#include "PatternsLib/Facade/HomeTheaterFacade.h"

namespace Patterns {

  HomeTheaterFacade::HomeTheaterFacade(std::weak_ptr<Amplifier> amp,
                                       std::weak_ptr<Tuner> tuner,
                                       std::weak_ptr<DvdPlayer> dvd,
                                       std::weak_ptr<CdPlayer> cd,
                                       std::weak_ptr<Projector> projector,
                                       std::weak_ptr<TheaterLights> lights,
                                       std::weak_ptr<Screen> screen,
                                       std::weak_ptr<PopcornPopper> popper) : 
    amp_(std::move(amp)),
    tuner_(std::move(tuner)),
    dvd_(std::move(dvd)),
    cd_(std::move(cd)),
    projector_(std::move(projector)),
    lights_(std::move(lights)),
    screen_(std::move(screen)),
    popper_(std::move(popper)) {
  }

  void HomeTheaterFacade::watchMovie(std::string movie) {
  }

}  // namespace Patterns