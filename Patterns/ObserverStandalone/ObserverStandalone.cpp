#include <memory>
#include <set>
#include <iostream>

namespace Ptn {
  class Observer {
   public:
    virtual ~Observer() {}
    virtual void notify() = 0;
  };

  class Subject {
   private:
    typedef std::weak_ptr<Observer> ObserverWeakPtr;
    std::set<ObserverWeakPtr, std::owner_less<ObserverWeakPtr>> observers_;
   public:
    void registerObserver(std::shared_ptr<Observer> o);
    void removeObserver(std::shared_ptr<Observer> o);
    void notifyObservers();
    virtual ~Subject();
  };

  Subject::~Subject() { }

  void Subject::registerObserver(std::shared_ptr<Observer> o) {
    observers_.insert(o);
  }
  void Subject::removeObserver(std::shared_ptr<Observer> o) {
    observers_.erase(o);
  }
  void Subject::notifyObservers() {
    auto iter = observers_.begin();
    while (iter != observers_.end()) {
      auto observer = iter->lock();
      if (observer) {
        observer->notify();
        ++iter;
      } else {
        iter = observers_.erase(iter);
      }
    }
  }

  class WeatherData : public Subject {
   private:
    float temperature_{ 0.0f };
    float humidity_{ 0.0f };
    float pressure_{ 0.0f };
   public:
    void measurementsChanged() {
      notifyObservers();
    }
    void setMeasurements(float temperature, float humidity, float pressure) {
      temperature_ = temperature;
      humidity_ = humidity;
      pressure_ = pressure;
      measurementsChanged();
    }
    float getTemperature() const { return temperature_; }
    float getHumidity() const { return humidity_; }
    float getPressure() const { return pressure_; }
  };

  class CurrentConditionsDisplay : public Observer {
   private:
    float temperature_{ 0.0f };
    float humidity_{ 0.0f };
    std::weak_ptr<WeatherData> weather_data_;
   public:
    void notify() override;
    void display();
    void setSubject(std::shared_ptr<WeatherData> data) { weather_data_ = data; }
    static std::shared_ptr<CurrentConditionsDisplay> create(std::shared_ptr<WeatherData> data);
  };

  void CurrentConditionsDisplay::notify() {
    auto weather_data = weather_data_.lock();
    if (weather_data) {
      temperature_ = weather_data->getTemperature();
      humidity_ = weather_data->getHumidity();
      display();
    }
  }
  void CurrentConditionsDisplay::display() {
    std::cout << "Current conditions: " << temperature_
      << "C degrees and " << humidity_ << "% humidity\n";
  }

  std::shared_ptr<CurrentConditionsDisplay> 
  CurrentConditionsDisplay::create(std::shared_ptr<WeatherData> data) {
    auto observer = std::make_shared<CurrentConditionsDisplay>();
    observer->setSubject(data);
    if (data)
      data->registerObserver(observer);
    return observer;
  }
}  // namespace Ptn

int main() {
  auto weather_data = std::make_shared<Ptn::WeatherData>();
  auto current_display = Ptn::CurrentConditionsDisplay::create(weather_data);
  weather_data->setMeasurements(30.0f, 65.0f, 30.4f);
  weather_data->setMeasurements(29.0f, 70.0f, 29.2f);
  weather_data->setMeasurements(17.0f, 90.0f, 29.2f);
}

