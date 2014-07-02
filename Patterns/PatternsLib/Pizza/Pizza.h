#pragma once
#include <string>
#include <vector>

namespace Patterns {

  class Pizza {
  private:
    std::string name_;
    std::string dough_;
    std::string sauce_;
    std::vector<std::string> toppings_;
  public:
    virtual ~Pizza() {}
    Pizza(std::string name, std::string dough, std::string sauce) 
      : name_(std::move(name)), dough_(std::move(dough)), sauce_(std::move(sauce)) {}
    virtual void prepare();
    virtual void bake();
    virtual void cut();
    virtual void box();
    void addTopping(std::string topping) { toppings_.emplace_back(std::move(topping)); }
    std::string getName() { return name_; }
  };


}  // namespace Patterns