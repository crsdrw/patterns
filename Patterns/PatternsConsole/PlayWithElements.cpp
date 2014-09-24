#include "PatternsConsole/PlayWIthElements.h"

#include <memory>
#include <string>
#include <vector>

class IElement {
public:
  virtual ~IElement() {}
  virtual void doThing() = 0;
};

class Element : public IElement {
private:
  unsigned atomic_protons_;
  float    mass_;
public:
  Element(unsigned protons, float mass) : atomic_protons_(protons), mass_(mass) {}
  void doThing() override { /* do normal thing Elements do */ }
};

class FlavoredElement : public IElement {
private:
  std::unique_ptr<IElement> element_;
  std::string flavor_;
public:
  FlavoredElement(std::unique_ptr<IElement> &&element, std::string flavor) :
    element_(std::move(element)), flavor_(std::move(flavor)) {}
  void doThing() override {
    // do special thing Flavored Elements do
    element_->doThing();
  }
};

class ColoredElement : public IElement {
private:
  std::unique_ptr<IElement> element_;
  std::string color_;
public:
  ColoredElement(std::unique_ptr<IElement> &&element, std::string color) :
    element_(std::move(element)), color_(std::move(color)) {}
  void doThing() override {
    // do special thing Colored Elements do
    element_->doThing();
  }
};

void playWithElements() {
  auto carbon = std::make_unique<Element>(6u, 12.0f);
  auto polonium = std::make_unique<Element>(84u, 209.0f);
  auto strawberry_polonium = std::make_unique<FlavoredElement>(std::move(polonium), "strawberry");
  auto pink_strawberry_polonium = std::make_unique<ColoredElement>(std::move(strawberry_polonium), "pink");

  std::vector<std::unique_ptr<IElement>> elements;
  elements.push_back(std::move(carbon));
  elements.push_back(std::move(pink_strawberry_polonium));

  for (auto& element : elements)
    element->doThing();
}