#pragma once
#include "CppUnitTestAssert.h"

#include "PatternsLib/MyString.h"

namespace MyAssert {
  template<typename T> void AreEqual(const T& expected, const T& actual, const std::string& message = "") {
    auto wmessage = MyString::widen(message);
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(expected, actual, wmessage.c_str());
  }

  template<typename T> void AreNotEqual(const T& notExpected, const T& actual, const std::string& message = "") {
    auto wmessage = MyString::widen(message);
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreNotEqual(notExpected, actual, wmessage.c_str());
  }

  inline void IsTrue(bool condition, const std::string& message = "") {
    auto wmessage = MyString::widen(message);
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::IsTrue(condition, wmessage.c_str());
  }

  template<typename T> void IsFalse(bool condition, const std::string& message = "") {
    auto wmessage = MyString::widen(message);
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::IsFalse(condition, wmessage.c_str());
  }

  template<typename T> void IsNull(const T* actual, const std::string& message = "") {
    auto wmessage = MyString::widen(message);
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::IsNull(actual, wmessage.c_str());
  }

  template<typename T> void IsNotNull(const T& actual, const std::string& message = "") {
    auto wmessage = MyString::widen(message);
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::IsNotNull(actual, wmessage.c_str());
  }

  template<typename T> void AreSame(const T& expected, const T& actual, const std::string) {
    auto wmessage = MyString::widen(message);
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreSame(expected, actual, wmessage.c_str());
  }

  template<typename T> void AreNotSame(const T& notExpected, const T& actual, const std::string& message = "") {
    auto wmessage = MyString::widen(message);
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreNotSame(notExpected, actual, wmessage.c_str());
  }

  template<typename E, typename F> void ExpectException(F functor, const std::string& message = "") {
    auto wmessage = MyString::widen(message);
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::ExpectException(functor, wmessage.c_str());
  }
}  // namespace MyAssert
