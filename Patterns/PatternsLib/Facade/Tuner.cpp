#include "PatternsLib/Facade/Tuner.h"
#include "PatternsLib/Facade/Amplifier.h"

namespace Patterns {

  Tuner::Tuner(std::string description, std::weak_ptr<Amplifier> amplifier) : 
    description_(std::move(description)), amplifier_(std::move(amplifier)), frequency_(0.0) {
  
  }

  void Tuner::setFrequency(double frequency) { 
    frequency_ = frequency;
    std::cout << description_ << " setting frequency to " << frequency_ << std::endl; 
  }


}  // namespace Patterns