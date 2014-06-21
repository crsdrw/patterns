#include "PatternsLib/ForecastDisplay.h"
#include "PatternsLib/WeatherData.h"
#include <iostream>
#include <cmath>

namespace {
  inline bool areAlmostEqual(float x, float y, float eps) { return std::abs(x - y) <= eps * std::abs(x); }
}

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
    if (current_pressure_ > last_pressure_)
      std::cout << "Improving weather on the way!\n";
    else if (areAlmostEqual(current_pressure_, last_pressure_, 1e-20f))
      std::cout << "More of the same\n";
    else if (current_pressure_ < last_pressure_)
      std::cout << "Watch out for cooler, rainy weather\n";
  }
}  // namespace Patterns
