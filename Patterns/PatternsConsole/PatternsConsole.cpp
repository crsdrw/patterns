#include "PatternsLib/MallardDuck.h"
#include "PatternsLib/ModelDuck.h"
#include "PatternsLib/FlyRocketPowered.h"
#include "PatternsLib/WeatherData.h"
#include "PatternsLib/CurrentConditionsDisplay.h"

namespace {
  void strategyTest() {
    using namespace Patterns;
    MallardDuck mallard;
    mallard.performQuack();
    mallard.performFly();

    ModelDuck model;
    model.performFly();
    model.setFlyBehaviour(FlyRocketPowered::create());
    model.performFly();
  }

  void observerTest() {
    Patterns::WeatherData weather_data;
    Patterns::CurrentConditionsDisplay current_display(&weather_data);
    weather_data.setMeasurements(80.0f, 65.0f, 30.4f);
    weather_data.setMeasurements(82.0f, 70.0f, 30.4f);
    weather_data.setMeasurements(78.0f, 90.0f, 30.4f);
  }
}

int main() {
  observerTest();
}

