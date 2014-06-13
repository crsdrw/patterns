#pragma once

#include "CppUnitTestLogger.h"

namespace MyLogger {
  inline void WriteMessage(const std::string& msg) {
    using Microsoft::VisualStudio::CppUnitTestFramework::Logger;
    Logger::WriteMessage(msg.c_str());
  }
}
