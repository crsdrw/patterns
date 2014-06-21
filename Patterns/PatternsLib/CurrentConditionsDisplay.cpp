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
  void
  CurrentConditionsDisplay::setWeatherData(std::shared_ptr<WeatherData> data) {
    weather_data_ = data;
    observe(data);
    notify();
  }
  // Static methods
  std::shared_ptr<CurrentConditionsDisplay> 
  CurrentConditionsDisplay::create(std::shared_ptr<WeatherData> data) {
    auto display = std::make_shared<CurrentConditionsDisplay>();
    display->setWeatherData(data);
    return display;
  }
}  // namespace Patterns