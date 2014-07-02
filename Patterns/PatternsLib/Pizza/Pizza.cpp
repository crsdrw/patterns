#include "PatternsLib/Pizza/Pizza.h"
#include "PatternsLib/Pizza/PizzaIngredientFactory.h"
#include "PatternsLib/Pizza/Dough.h"
#include "PatternsLib/Pizza/Sauce.h"
#include "PatternsLib/Pizza/Cheese.h"
#include "PatternsLib/Pizza/Veggie.h"
#include "PatternsLib/Pizza/Clam.h"
#include <iostream>

namespace Patterns {

  Pizza::Pizza(std::string name, std::unique_ptr<PizzaIngredientFactory> ingredient_factory) 
    : name_(std::move(name)), ingredient_factory_(std::move(ingredient_factory)) {
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

  std::string Pizza::toString() const {
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
    if (!veggies_.empty()) result.append("\n");
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

  void Pizza::setClam(std::unique_ptr<Clam> clam) {
    clam_ = std::move(clam);
  }

  PizzaIngredientFactory* Pizza::getIngredientFactory() {
    return ingredient_factory_.get();
  }
}  // namespace Patterns
