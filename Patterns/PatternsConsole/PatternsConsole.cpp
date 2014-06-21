#include "PatternsLib/MallardDuck.h"
#include "PatternsLib/ModelDuck.h"
#include "PatternsLib/FlyRocketPowered.h"
#include "PatternsLib/WeatherData.h"
#include "PatternsLib/CurrentConditionsDisplay.h"
#include "PatternsLib/ForecastDisplay.h"

namespace {
  void strategyTest() {
    using Patterns::MallardDuck;
    using Patterns::ModelDuck;
    MallardDuck mallard;
    mallard.performQuack();
    mallard.performFly();

    ModelDuck model;
    model.performFly();
    model.setFlyBehaviour(Patterns::FlyRocketPowered::create());
    model.performFly();
  }
  void observerTest() {
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
}  // namespace

int main() {
  observerTest();
}

