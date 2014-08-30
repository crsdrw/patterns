#include "PatternsConsole/PlayWithDucks.h"
#include "PatternsLib/Facade/Amplifier.h"
#include "PatternsLib/Facade/CdPlayer.h"


namespace Patterns {
  void playWithHomeTheater() {
    auto amplifier = std::make_shared<Amplifier>("Yamaha RX-V377");
    auto cd = std::make_shared<CdPlayer>("Marantz A8005", amplifier);
  }
}