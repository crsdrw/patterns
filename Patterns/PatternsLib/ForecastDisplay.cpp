#include "PatternsLib/ForecastDisplay.h"
#include "PatternsLib/WeatherData.h"
#include <iostream>

namespace Patterns {
  void
  ForecastDisplay::notify() {
    auto weather_data = weather_data_.lock();
    if (weather_data) {
      last_pressure_ = current_pressure_;
      current_pressure_ = weather_data->getPressure();
      display();
    }
  }

  void
  ForecastDisplay::display() {
    std::cout << "Forecast: ";
    if (current_pressure_ > last_pressure_) {
      std::cout << "Improving weather on the way!";
    }
    else if (current_pressure_ == last_pressure_) {
      System.out.println("More of the same");
    }
    else if (currentPressure < lastPressure) {
      System.out.println("Watch out for cooler, rainy weather");
    }
  }

  void
  ForecastDisplay::setWeatherData(std::shared_ptr<WeatherData> data) {
    weather_data_ = data;
    observe(data);
    notify();
  }

  // Static methods
  std::shared_ptr<ForecastDisplay>
    ForecastDisplay::create(std::shared_ptr<WeatherData> data) {
    auto display = std::make_shared<CurrentConditionsDisplay>();
    display->setWeatherData(data);
    return display;
  }
}