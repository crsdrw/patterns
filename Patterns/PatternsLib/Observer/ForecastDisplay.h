#pragma once

#include "PatternsLib/Observer/Observer.h"

namespace Patterns {
  class WeatherData;

  class ForecastDisplay : public Observer {
   private:
    float current_pressure_{0.0f};
    float last_pressure_{0.0f};
    std::weak_ptr<WeatherData> weather_data_;
   public:
    void notify() override;
    void display();
    void setSubject(std::shared_ptr<WeatherData> data) { weather_data_ = data; }
  };
}  // namespace Patterns
