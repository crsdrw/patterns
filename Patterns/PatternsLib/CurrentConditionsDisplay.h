#pragma once

#include "PatternsLib/Observer.h"

namespace Patterns {
  class WeatherData;

  class CurrentConditionsDisplay : public Observer {
   private:
    float temperature_{0.0f};
    float humidity_{0.0f};
    std::weak_ptr<WeatherData> weather_data_;
   public:
    void notify() override;
    void display();
    void setSubject(std::shared_ptr<WeatherData> data) { weather_data_ = data; }
  };
}  // namespace Patterns
