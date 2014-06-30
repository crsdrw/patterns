#include "PatternsLib/Pizza.h"
#include "PatternsLib/Dough.h"
#include "PatternsLib/Sauce.h"
#include "PatternsLib/Cheese.h"
#include "PatternsLib/Veggie.h"
#include "PatternsLib/Clam.h"
#include <iostream>

namespace Patterns {

  Pizza::Pizza(std::string name) : name_(std::move(name)) {
  }

  Pizza::~Pizza() {}

  void Pizza::bake() {
    std::cout << "Bake for 25 minutes at 350\n";
  }

  void Pizza::cut() {
    std::cout << "Cutting the pizza into diagonal slices\n";
  }

  void Pizza::box() {
    std::cout << "Place pizza in official PizzaStore box\n";
  }

  void Pizza::setDough(std::unique_ptr<Dough> dough) {
    dough_ = std::move(dough);
  }

  std::string Pizza::toString() {
    std::string result("---- " + name_ + " ----\n");
    if(dough_) {
      result.append(dough_->toString());
      result.append("\n");
    }
    if(sauce_) {
      result.append(sauce_->toString());
      result.append("\n");
    }
    if(cheese_) {
      result.append(cheese_->toString());
      result.append("\n");
    }
    std::string separator = "";
    for (auto& veggie : veggies_) {
      result.append(separator);
      result.append(veggie->toString());
      separator = ", ";
    }
    result.append("\n");
    if(clam_) {
      result.append(clam_->toString());
      result.append("\n");
    }
    return result;
  }

  void Pizza::setSauce(std::unique_ptr<Sauce> sauce) {
    sauce_ = std::move(sauce);
  }

  void Pizza::setCheese(std::unique_ptr<Cheese> cheese) {
    cheese_ = std::move(cheese);
  }
}  // namespace Patterns
