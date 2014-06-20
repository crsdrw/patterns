#pragma once

#include "PatternsLib/Observer.h"
#include "PatternsLib/DisplayElement.h"
#include "PatternsLib/WeatherData.h"
#include <iostream>

namespace Patterns {
  class CurrentConditionsDisplay : public Observer, public DisplayElement {
  private:
    float temperature_{0.0f};
    float humidity_{0.0f};
    std::weak_ptr<WeatherData> weather_data_;

  public:
    CurrentConditionsDisplay(std::shared_ptr<WeatherData> weather_data) : Observer(weather_data), weather_data_(weather_data) {
    }
    void notify() override {
      auto weather_data = weather_data_.lock();
      if (weather_data) {
        temperature_ = weather_data->getTemperature();
        humidity_ = weather_data->getHumidity();
        display();
      }
    }
    void display() override {
      std::cout << "Current conditions: " << temperature_ 
        << "C degrees and " << humidity_ << "% humidity\n";
    }
  };
}  // namespace Patterns