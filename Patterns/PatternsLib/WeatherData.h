#pragma once

#include "PatternsLib/Subject.h"
#include "PatternsLib/Observer.h"

#include <unordered_set>

namespace Patterns {
  class WeatherData : public Subject {
  private:
    std::unordered_set<Observer *> observers;
    float temperature;
    float humidity;
    float pressure;
  public:
    void registerObserver(Observer* o) override {
      observers.insert(o);
    }
    void removeObserver(Observer* o) override {
      observers.erase(o);
    }
    void notifyObservers() const override {
      for (auto observer : observers)
        observer->update(temperature, humidity, pressure);
    }
    void measurementsChanged() {
      notifyObservers();
    }
    void setMeasurements(float temp, float hum, float pres) {
      temperature = temp;
      humidity = hum;
      pressure = pres;
      measurementsChanged();
    }
  };
}  // namespace Patterns