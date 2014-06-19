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
    WeatherData* weather_data_;

  public:
    CurrentConditionsDisplay(WeatherData* weather_data) : weather_data_(weather_data) {
      if (weather_data) weather_data_->registerObserver(this);
    }
    void notify() override {
      if (weather_data_) {
        temperature_ = weather_data_->getTemperature();
        humidity_ = weather_data_->getHumidity();
        display();
      }
    }
    void display() override {
      std::cout << "Current conditions: " << temperature_ 
        << "C degrees and " << humidity_ << "% humidity\n";
    }
  };
}  // namespace Patterns