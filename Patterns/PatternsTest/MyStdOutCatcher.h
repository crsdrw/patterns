#pragma once

#include <sstream>
#include <streambuf>
#include <iostream>
#include <memory>
#include <functional>
#include <string>

class MyStdOutCatcher {
private:
  std::stringstream  buffer_;
  std::unique_ptr<std::streambuf, std::function<void(std::streambuf*)>> sbuf_;
  static void setStdOut(std::streambuf* buf) { std::cout.rdbuf(buf); }
public:
  MyStdOutCatcher() : sbuf_(std::cout.rdbuf(), setStdOut) { setStdOut(buffer_.rdbuf()); }
  std::string read() { std::string output = buffer_.str(); buffer_.str(""); return output; }
};