#include "PatternsLib/MyString.h"

#include <locale>
#include <codecvt>

namespace MyString {

  std::wstring widen(const std::string& string) {
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    return converter.from_bytes(string);
  }
}
