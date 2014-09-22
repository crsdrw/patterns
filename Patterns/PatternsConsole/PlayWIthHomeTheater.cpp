#include "PatternsConsole/PlayWithDucks.h"
#include "PatternsLib/Facade/Amplifier.h"
#include "PatternsLib/Facade/CdPlayer.h"
#include "PatternsLib/Facade/DvdPlayer.h"
#include "PatternsLib/Facade/Screen.h"
#include "PatternsLib/Facade/PopcornPopper.h"
#include "PatternsLib/Facade/Tuner.h"
#include "PatternsLib/Facade/TheaterLights.h"
#include "PatternsLib/Facade/Projector.h"
#include "PatternsLib/Facade/HomeTheaterFacade.h"


namespace Patterns {
  void playWithHomeTheater() {

    // Create all the parts of the home theatre system
    Amplifier amp("Top-O-Line Amplifier");
    CdPlayer cd("Top-O-Line CD Player", &amp);
    DvdPlayer dvd("Top-O-Line DVD Player", &amp);
    Screen screen("My Theater Screen");
    PopcornPopper popper("My Popcorn Popper");
    Tuner tuner("Top-O-Line AM/FM Tuner", &amp);
    TheaterLights lights("Theater Ceiling Lights");
    Projector projector("Top-O-Line Projector");

    popper.on();  // Turn on the popcorn popper...
    popper.pop(); // and start popping...

    lights.dim(10); // Dim the lights to 10%... 
    
    screen.down();  // Put the screen down...

    projector.on();             // Turn on the projector...
    projector.setInput(&dvd);    // set it to DVD...
    projector.wideScreenMode(); // and put it on wide screen mode for the movie...

    amp.on();                // Turn on the amp...
    amp.setInput(&dvd);       // set it to DVD and...
    amp.setSurroundSound();  // put it into surround sound mode...
    amp.setVolume(11);       // and set the volume to 11...

    dvd.on();                            // Turn on the DVD player...
    dvd.play("Raiders of the lost ark"); // and FINALLY, play the movie!

    // What about shutting everything down again?!
    // How would you play a CD? etc...
  }

  void playWithHomeTheaterFacade() {
    // Create all the parts of the home theatre system
    // Not encapsulated or owned by the facade.
    Amplifier amp("Top-O-Line Amplifier");
    CdPlayer cd("Top-O-Line CD Player", &amp);
    DvdPlayer dvd("Top-O-Line DVD Player", &amp);
    Screen screen("My Theater Screen");
    PopcornPopper popper("My Popcorn Popper");
    Tuner tuner("Top-O-Line AM/FM Tuner", &amp);
    TheaterLights lights("Theater Ceiling Lights");
    Projector projector("Top-O-Line Projector");

    HomeTheaterFacade theater(&amp, &tuner, &dvd, &cd, &projector, &lights, &screen, &popper);
    theater.watchMovie("Raiders of the Lost Ark");
    theater.endMovie();
  }
}