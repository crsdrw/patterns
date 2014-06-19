#pragma once

#include "PatternsLib/Subject.h"
#include "PatternsLib/Observer.h"
#include <unordered_set>

namespace Patterns {
  class WeatherData : public Subject {
  private:
    float temperature_{0.0f};
    float humidity_{0.0f};
    float pressure_{0.0f};
  public:
    void measurementsChanged() {
      notifyObservers();
    }
    void setMeasurements(float temperature, float humidity, float pressure) {
      temperature_ = temperature;
      humidity_ = humidity;
      pressure_ = pressure;
      measurementsChanged();
    }
    float getTemperature() const { return temperature_; }
    float getHumidity() const { return humidity_; }
    float getPressure() const { return pressure_; }
  };
}  // namespace Patterns