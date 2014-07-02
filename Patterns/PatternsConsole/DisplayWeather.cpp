#include "PatternsConsole/DisplayWeather.h"
#include "PatternsLib/Observer/WeatherData.h"
#include "PatternsLib/Observer/CurrentConditionsDisplay.h"
#include "PatternsLib/Observer/ForecastDisplay.h"

namespace Patterns {
  void displayWeather() {
    using Patterns::WeatherData;
    using Patterns::CurrentConditionsDisplay;
    using Patterns::ForecastDisplay;
    auto weather_data = std::make_shared<WeatherData>();
    auto current_display = Patterns::makeObserver<CurrentConditionsDisplay>(weather_data);
    auto forecast_display = Patterns::makeObserver<ForecastDisplay>(weather_data);
    weather_data->setMeasurements(30.0f, 65.0f, 30.4f);
    weather_data->setMeasurements(29.0f, 70.0f, 29.2f);
    weather_data->setMeasurements(17.0f, 90.0f, 29.2f);
  }
}
