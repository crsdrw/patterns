#include <set>
#include <iostream>

namespace {
  class Subject;

  class Observer {
   protected:
    ~Observer() {}
   public:
    explicit Observer(Subject* s);
    virtual void notify() = 0;
  };

  class Subject {
   private:
    std::set<Observer *> observers_;
   protected:
    ~Subject() {}
   public:
    void registerObserver(Observer* o) {
      if (o) observers_.insert(o);
    }
    void removeObserver(Observer* o) {
      observers_.erase(o);
    }
    void notifyObservers() const {
      for (auto observer : observers_)
        observer->notify();
    }
  };

  Observer::Observer(Subject* subject) {
    if (subject)
      subject->registerObserver(this);
  }

  class WeatherData : public Subject {
   private:
    float temperature_{ 0.0f };
    float humidity_{ 0.0f };
    float pressure_{ 0.0f };
   public:
    void setMeasurements(float temperature, float humidity, float pressure) {
      temperature_ = temperature;
      humidity_ = humidity;
      pressure_ = pressure;
      notifyObservers();
    }
    float getTemperature() const { return temperature_; }
    float getHumidity() const { return humidity_; }
    float getPressure() const { return pressure_; }
  };

  class CurrentConditionsDisplay : public Observer {
   private:
    float temperature_{ 0.0f };
    float humidity_{ 0.0f };
    WeatherData* weather_data_;
   public:
    explicit CurrentConditionsDisplay(WeatherData* data) : Observer(data), weather_data_(data) { }
    void notify() override {
      if (weather_data_) {
        temperature_ = weather_data_->getTemperature();
        humidity_ = weather_data_->getHumidity();
        display();
      }
    }
    void display() {
      std::cout << "Current conditions: " << temperature_
        << "C degrees and " << humidity_ << "% humidity\n";
    }
  };
}  // namespace

int main() {
  WeatherData weather_data;
  CurrentConditionsDisplay current_display(&weather_data);
  weather_data.setMeasurements(30.0f, 65.0f, 30.4f);
  weather_data.setMeasurements(29.0f, 70.0f, 29.2f);
  weather_data.setMeasurements(17.0f, 90.0f, 29.2f);
}
