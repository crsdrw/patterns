#include "PatternsLib/MallardDuck.h"
#include "PatternsLib/ModelDuck.h"
#include "PatternsLib/FlyRocketPowered.h"
#include "PatternsLib/WeatherData.h"
#include "PatternsLib/CurrentConditionsDisplay.h"

namespace {
  void strategyTest() {
    Patterns::MallardDuck mallard;
    mallard.performQuack();
    mallard.performFly();

    Patterns::ModelDuck model;
    model.performFly();
    model.setFlyBehaviour(Patterns::FlyRocketPowered::create());
    model.performFly();
  }
  void observerTest() {
    auto weather_data = std::make_shared<Patterns::WeatherData>();
    auto current_display = std::make_shared<Patterns::CurrentConditionsDisplay>(weather_data);
    weather_data->setMeasurements(30.0f, 65.0f, 30.4f);
    weather_data->setMeasurements(29.0f, 70.0f, 29.2f);
    weather_data->setMeasurements(17.0f, 90.0f, 29.2f);
  }
}  // namespace

int main() {
  observerTest();
}

