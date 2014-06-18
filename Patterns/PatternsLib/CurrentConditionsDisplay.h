#pragma once

#include "PatternsLib/Observer.h"
#include "PatternsLib/DisplayElement.h"
#include "PatternsLib/Subject.h"
#include <iostream>

namespace Patterns {
  class CurrentConditionsDisplay : public Observer, public DisplayElement {
  private:
    float temperature_;
    float humidity_;
    Subject* weather_data_;

  public:
    CurrentConditionsDisplay(Subject* weather_data) {
      weather_data_ = weather_data;
      weather_data_->registerObserver(this);
    }
    void update(float temperature, float humidity, float /*pressure*/) override {
      temperature_ = temperature;
      humidity_ = humidity;
      display();
    }
    void display() {
      std::cout << "Current conditions: " << temperature_ 
        << "C degrees and " << humidity_ << "% humidity\n";
    }
  };
}  // namespace Patterns