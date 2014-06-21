#include "PatternsLib/CurrentConditionsDisplay.h"
#include "PatternsLib/WeatherData.h"
#include <iostream>

namespace Patterns {
  void
  CurrentConditionsDisplay::notify() {
    auto weather_data = weather_data_.lock();
    if (weather_data) {
      temperature_ = weather_data->getTemperature();
      humidity_ = weather_data->getHumidity();
      display();
    }
  }
  void
  CurrentConditionsDisplay::display() {
    std::cout << "Current conditions: " << temperature_
      << "C degrees and " << humidity_ << "% humidity\n";
  }
}  // namespace Patterns
