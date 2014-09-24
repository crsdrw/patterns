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

    // Perhaps std::weak_ptr for the subsystems would more appropriate in practice?
    Amplifier*     amp_;
    Tuner*         tuner_;
    DvdPlayer*     dvd_;
    CdPlayer*      cd_;
    Projector*     projector_;
    TheaterLights* lights_;
    Screen*        screen_;
    PopcornPopper* popper_;

  public:
    HomeTheaterFacade(Amplifier* amp,
                      Tuner* tuner,
                      DvdPlayer* dvd,
                      CdPlayer* cd,
                      Projector* projector,
                      TheaterLights* lights,
                      Screen* screen,
                      PopcornPopper* popper);  // Perhaps use setters instead of constructor?
    void watchMovie(std::string movie);
    void endMovie();
    void listenToCd(std::string title);
    void endCd();
    void listenToRadio(double frequency);
    void endRadio();
  };

}  // namespace Patterns
