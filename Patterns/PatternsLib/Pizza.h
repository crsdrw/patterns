#pragma once
#include <string>
#include <vector>
#include <memory>

namespace Patterns {

  class Dough;
  class Sauce;
  class Cheese;
  class Veggie;
  class Clam;

  class Pizza {
  private:
    std::string name_;
    std::unique_ptr<Dough> dough_;
    std::unique_ptr<Sauce> sauce_;
    std::unique_ptr<Cheese> cheese_;
    std::unique_ptr<Clam> clam_;
    std::vector<std::unique_ptr<Veggie>> veggies_;
  public:
    virtual ~Pizza();
    Pizza(std::string name);
    virtual void prepare() = 0;
    virtual void bake();
    virtual void cut();
    virtual void box();
    std::string getName() { return name_; }
    std::string toString();
    void setDough(std::unique_ptr<Dough> dough);
    void setSauce(std::unique_ptr<Sauce> sauce);
    void setCheese(std::unique_ptr<Cheese> cheese);
    void setClam(std::unique_ptr<Clam> clam);
  };
}  // namespace Patterns