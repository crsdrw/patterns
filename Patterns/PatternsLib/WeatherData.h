#pragma once

#include "PatternsLib/Subject.h"
#include "PatternsLib/Observer.h"
#include <unordered_set>

namespace Patterns {

  class WeatherData : public Subject {
  private:
    std::unordered_set<Observer *> observers_;
    float temperature_;
    float humidity_;
    float pressure_;
  public:
    void registerObserver(Observer* o) {
      observers_.insert(o);
    }
    void removeObserver(Observer* o) {
      observers_.erase(o);
    }
    void notifyObservers() const override {
      for (auto observer : observers_)
        observer->update(temperature_, humidity_, pressure_);
    }
    void measurementsChanged() {
      notifyObservers();
    }
    void setMeasurements(float temperature, float humidity, float pressure) {
      temperature_ = temperature;
      humidity_ = humidity;
      pressure_ = pressure;
      measurementsChanged();
    }
  };
}  // namespace Patterns