#include "stdafx.h"
#include "CppUnitTest.h"
#include "PatternsLib/WeatherData.h"
#include "PatternsLib/CurrentConditionsDisplay.h"
#include "PatternsTest/MyStdOutCatcher.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PatternsTest
{
	TEST_CLASS(ObserverTest)
	{
	public:
		
		TEST_METHOD(TestWeatherStation)
		{
      Patterns::WeatherData weather_data;
      Patterns::CurrentConditionsDisplay current_display(&weather_data);
      MyStdOutCatcher stdOutCatcher;
      weather_data.setMeasurements(19.0f, 65.0f, 30.4f);
      Assert::AreEqual(std::string("Current conditions: 19C degrees and 65% humidity\n"), stdOutCatcher.read());
      weather_data.setMeasurements(20.0f, 70.0f, 29.2f);
      Assert::AreEqual(std::string("Current conditions: 20C degrees and 70% humidity\n"), stdOutCatcher.read());
      weather_data.setMeasurements(17.0f, 90.0f, 29.2f);
      Assert::AreEqual(std::string("Current conditions: 17C degrees and 90% humidity\n"), stdOutCatcher.read());
		}

	};
}
