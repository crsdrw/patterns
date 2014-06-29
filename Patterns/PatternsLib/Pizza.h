#pragma once
#include <string>
#include <vector>
#include <memory>

namespace Patterns {

  class Dough;
  class Sauce;
  class Veggie;

  class Pizza {
  private:
    std::string name_;
    std::unique_ptr<Dough> dough_;
    std::unique_ptr<Sauce> sauce_;
    std::vector<std::unique_ptr<Veggie>> toppings_;
  public:
    virtual ~Pizza() {}
    Pizza(std::string name);
    virtual void prepare() = 0;
    virtual void bake();
    virtual void cut();
    virtual void box();
    void addTopping(std::string topping) { toppings_.emplace_back(std::move(topping)); }
    std::string getName() { return name_; }
  };


}  // namespace Patterns