#pragma once

#include "PatternsLib/Subject.h"
#include "PatternsLib/Observer.h"
#include "PatternsLib/DisplayElement.h"
#include <iostream>

namespace Patterns {
  class CurrentConditionsDisplay : public Observer, public DisplayElement {
  private:
    float temperature;
    float humidity;
    Subject *weather_data;
  public:
    CurrentConditionsDisplay(Subject *weather_data_subject) : weather_data(weather_data_subject) {
      if (weather_data) weather_data->registerObserver(this);
    }
    void update(float temp, float hum, float /*press*/) override {
      temperature = temp;
      humidity = hum;
      display();
    }
    void display() override {
      std::cout << "Current conditions: " << temperature << "C degrees and " << humidity << "% humidity\n";
    }
  };
}