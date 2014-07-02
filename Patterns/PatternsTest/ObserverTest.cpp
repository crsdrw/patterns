#include "stdafx.h"
#include "CppUnitTest.h"
#include "PatternsLib/Observer/Observer.h"
#include "PatternsLib/Observer/WeatherData.h"
#include "PatternsLib/Observer/CurrentConditionsDisplay.h"
#include "PatternsLib/Observer/Subject.h"
#include "PatternsTest/MyStdOutCatcher.h"
#include "PatternsTest/MyAssert.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace {
  using Patterns::Observer;
  using Patterns::Subject;

  class TestSubject : public Subject {

  };

  class TestObserver : public Observer {
   public: 
    int notify_count_{0};
    std::weak_ptr<TestSubject> subject_;

    void notify() override { notify_count_++; }
    void setSubject(std::shared_ptr<TestSubject> subject) { subject_ = subject; }
  };

  typedef std::vector<std::shared_ptr<TestObserver>> ObserverVector;

  // Observer that deletes other Observers on notify!
  class ObserverDeleter : public TestObserver {
   public:
    ObserverVector *other_observers_;
    ObserverDeleter(ObserverVector *observers) : other_observers_(observers) {}
    void notify() override { TestObserver::notify(); other_observers_->clear(); }
  };

  class ObserverAdder : public TestObserver {
  public:
    ObserverVector other_observers_;

    // adds observers to the subject during notify!
    void notify() override { 
      TestObserver::notify();
      auto subject = subject_.lock();
      other_observers_.push_back(Patterns::makeObserver<TestObserver>(subject));
    }
  };
}

namespace PatternsTest
{
	TEST_CLASS(ObserverTest)
	{
	public:
    TEST_METHOD(TestEmptySubject)
    {
      auto subject = std::make_shared<TestSubject>();
      subject->notifyObservers();
      subject->registerObserver(nullptr);
      subject->notifyObservers();
      subject->removeObserver(nullptr);
    }

    TEST_METHOD(TestNotifyCollectionOfObservers) {
      auto subject = std::make_shared<TestSubject>();
      ObserverVector observers;
      for (int i = 0; i != 5; ++i)
        observers.push_back(Patterns::makeObserver<TestObserver>(subject));
      for (int i = 0; i != 5; ++i)
        Assert::AreEqual(0, observers[i]->notify_count_);
      subject->notifyObservers();
      for (int i = 0; i != 5; ++i)
        Assert::AreEqual(1, observers[i]->notify_count_);
    }

    TEST_METHOD(ObserverDeletesOtherObserver)
    {
      auto subject = std::make_shared<TestSubject>();
      ObserverVector observers; // observers that will be deleted
      auto observer_deleter = Patterns::makeObserver<ObserverDeleter>(subject, &observers);

      for (int i = 0; i != 3; ++i) // add some sacrificial observers before the deleter
        observers.push_back(Patterns::makeObserver<TestObserver>(subject));
      subject->registerObserver(observer_deleter);
      auto safe_observer = Patterns::makeObserver<TestObserver>(subject);
      for (int i = 0; i != 3; ++i) // add some sacrifical observers after the deleter
        observers.push_back(Patterns::makeObserver<TestObserver>(subject));
      
      subject->notifyObservers();  // this notify will cause sacrifical observers to be deleted

      Assert::AreEqual(1, safe_observer->notify_count_);  // check that first notify succeeded
      subject->notifyObservers();
      Assert::AreEqual(2, safe_observer->notify_count_); // check that can still notify
    }

    TEST_METHOD(ObserverAddsOtherObservers)
    {
      auto subject = std::make_shared<TestSubject>();
      ObserverVector observers; // filler observers
      for (int i = 0; i != 3; ++i) // add some filler observers before the adder
        observers.push_back(Patterns::makeObserver<TestObserver>(subject));

      auto observer_adder = Patterns::makeObserver<ObserverAdder>(subject);

      for (int i = 0; i != 3; ++i) // add some filler observers after the adder
        observers.push_back(Patterns::makeObserver<TestObserver>(subject));

      subject->notifyObservers();
      Assert::AreEqual(1u, observer_adder->other_observers_.size());

      // check all original observers have been notified
      for (auto observer : observers)
        Assert::AreEqual(1, observer->notify_count_);
    }

    TEST_METHOD(ObserverDeletesAllObservers)
    {
      auto subject = std::make_shared<TestSubject>();
      ObserverVector observers; // observers that will be deleted

      for (int i = 0; i != 3; ++i) // add some sacrificial observers before the deleter
        observers.push_back(Patterns::makeObserver<TestObserver>(subject));

      observers.push_back(Patterns::makeObserver<ObserverDeleter>(subject, &observers));

      for (int i = 0; i != 3; ++i) // add some sacrifical observers after the deleter
        observers.push_back(Patterns::makeObserver<TestObserver>(subject));

      subject->notifyObservers();
      subject->notifyObservers();
    }

		TEST_METHOD(TestCreateObserver)
		{
      auto subject = std::make_shared<TestSubject>();
      auto observer = Patterns::makeObserver<TestObserver>(subject);
      auto observed_subject = observer->subject_.lock();
      Assert::IsTrue(subject == observed_subject);
      Assert::AreEqual(0, observer->notify_count_);
		}

    TEST_METHOD(TestNotifyObserver)
    {
      auto subject = std::make_shared<TestSubject>();
      auto observer = Patterns::makeObserver<TestObserver>(subject);
      subject->notifyObservers();
      Assert::AreEqual(1, observer->notify_count_);
    }
	
    TEST_METHOD(AddRValueObserver)
    {
      auto subject = std::make_shared<TestSubject>();
      subject->registerObserver(Patterns::makeObserver<TestObserver>(subject));
      subject->notifyObservers();
    }

    TEST_METHOD(AddEmptyObserver)
    {
      auto subject = std::make_shared<TestSubject>();
      auto observer = std::make_shared<TestObserver>();
      subject->registerObserver(observer);
      Assert::AreEqual(0, observer->notify_count_);
      Assert::IsTrue(observer->subject_.expired());
      subject->notifyObservers();
      Assert::AreEqual(1, observer->notify_count_);
      Assert::IsTrue(observer->subject_.expired());
    }

		TEST_METHOD(TestWeatherStation)
		{
      using Patterns::WeatherData;
      using Patterns::CurrentConditionsDisplay;
      auto weather_data = std::make_shared<WeatherData>();
      auto current_conditions = Patterns::makeObserver<CurrentConditionsDisplay>(weather_data);
      MyStdOutCatcher stdOutCatcher;
      weather_data->setMeasurements(19.0f, 65.0f, 30.4f);
      MyAssert::AreEqual("Current conditions: 19C degrees and 65% humidity\n", stdOutCatcher.read());
      weather_data->setMeasurements(20.0f, 70.0f, 29.2f);
      MyAssert::AreEqual("Current conditions: 20C degrees and 70% humidity\n", stdOutCatcher.read());
      weather_data->setMeasurements(17.0f, 90.0f, 29.2f);
      MyAssert::AreEqual("Current conditions: 17C degrees and 90% humidity\n", stdOutCatcher.read());
		}
			
	};
}