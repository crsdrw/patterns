#pragma once
#include <memory>
#include <string>

namespace Patterns {

  class Amplifier;
  class Tuner;
  class DvdPlayer;
  class CdPlayer;
  class Projector;
  class TheaterLights;
  class Screen;
  class PopcornPopper;

  class HomeTheaterFacade {
  private:
    std::weak_ptr<Amplifier> amp_;
    std::weak_ptr<Tuner> tuner_;
    std::weak_ptr<DvdPlayer> dvd_;
    std::weak_ptr<CdPlayer> cd_;
    std::weak_ptr<Projector> projector_;
    std::weak_ptr<TheaterLights> lights_;
    std::weak_ptr<Screen> screen_;
    std::weak_ptr<PopcornPopper> popper_;
  public:
    HomeTheaterFacade(std::weak_ptr<Amplifier> amp,
                      std::weak_ptr<Tuner> tuner,
                      std::weak_ptr<DvdPlayer> dvd,
                      std::weak_ptr<CdPlayer> cd,
                      std::weak_ptr<Projector> projector,
                      std::weak_ptr<TheaterLights> lights,
                      std::weak_ptr<Screen> screen,
                      std::weak_ptr<PopcornPopper> popper);
    void watchMovie(std::string movie);
    void endMovie();
  };

}  // namespace Patterns