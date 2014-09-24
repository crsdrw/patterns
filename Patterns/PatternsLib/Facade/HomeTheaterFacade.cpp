#include "PatternsLib/Facade/HomeTheaterFacade.h"

#include "PatternsLib/Facade/Amplifier.h"
#include "PatternsLib/Facade/Tuner.h"
#include "PatternsLib/Facade/DvdPlayer.h"
#include "PatternsLib/Facade/CdPlayer.h"
#include "PatternsLib/Facade/Projector.h"
#include "PatternsLib/Facade/TheaterLights.h"
#include "PatternsLib/Facade/Screen.h"
#include "PatternsLib/Facade/PopcornPopper.h"

#include <iostream>

namespace Patterns {

  HomeTheaterFacade::HomeTheaterFacade(Amplifier* amp, Tuner* tuner, DvdPlayer* dvd, CdPlayer* cd,
    Projector* projector, TheaterLights* lights, Screen* screen, PopcornPopper* popper) :
    amp_(amp), tuner_(tuner), dvd_(dvd), cd_(cd), projector_(projector),
    lights_(lights), screen_(screen), popper_(popper) {
  }

  void HomeTheaterFacade::watchMovie(std::string movie) {
    std::cout << "Getting ready to watch a move...\n";
    popper_->on();
    popper_->pop();
    lights_->dim(10);
    screen_->down();
    projector_->on();
    projector_->setInput(dvd_);
    projector_->wideScreenMode();
    amp_->on();
    amp_->setInput(dvd_);
    amp_->setSurroundSound();
    amp_->setVolume(5);
    dvd_->on();
    dvd_->play(std::move(movie));
  }

  void HomeTheaterFacade::endMovie() {
    std::cout << "Shutting movie theater down..\n";
    popper_->off();
    lights_->on();
    screen_->up();
    projector_->off();
    amp_->off();
    dvd_->stop();
    dvd_->eject();
    dvd_->off();
  }

  void HomeTheaterFacade::listenToCd(std::string title) {
    std::cout << "Get ready for an audiopile experence...\n";
    lights_->on();
    amp_->on();
    amp_->setVolume(5);
    amp_->setInput(cd_);
    amp_->setStereoSound();
    cd_->on();
    cd_->play(std::move(title));
  }

  void HomeTheaterFacade::endCd() {
    std::cout << "Shutting down CD...\n";
    amp_->off();
    cd_->eject();
    cd_->off();
  }

  void HomeTheaterFacade::listenToRadio(double frequency) {
    std::cout << "Tuning in the airwaves...\n";
    amp_->on();
    amp_->setVolume(5);
    amp_->setInput(tuner_);
    amp_->setStereoSound();
    tuner_->on();
    tuner_->setFrequency(frequency);
  }

  void HomeTheaterFacade::endRadio() {
    std::cout << "Shutting down the tuner...\n";
    amp_->off();
    tuner_->off();
  }

}  // namespace Patterns