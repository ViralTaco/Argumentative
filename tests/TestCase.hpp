#ifndef VT_ARGUMENTATIVETEST_TESTS_TESTCASE_HPP_
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ TestCase.hpp:                                        ┃
// ┃ Copyright (c) 2020 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                         ┃
// ┃ SPDX-License-Identifier: MIT                         ┃
// ┃ <http://www.opensource.org/licenses/MIT>             ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_ARGUMENTATIVETEST_TESTS_TESTCASE_HPP_ "1.2.0"

#include "assert.hpp"

#include <initializer_list>
#include <string_view>
#include <ios>
#include <iostream>
#include <iomanip>

namespace viraltaco_ {
class TestCase {
public: // alias
  using Lambda = void(*)();
  
private: // members
  std::string_view test_str_;
  Lambda test_;
  
public: // inits
  constexpr TestCase(std::string_view test_str, Lambda test) noexcept
    : test_str_{ test_str }
    , test_{ test }
  {}

public: // class methods
  static constexpr auto run = [] (auto const& self) {
    const auto padding = (60 - 8) - self.test_str_.length();
    std::cout << "Testing " << self.test_str_ << ':';
    if (padding > 0) { std::cout << std::setw(padding); }
    else { std::cout << std::setw(1); }
    std::cout << std::right;
    std::cout.flush();
    try {
      self.test_();
      std::cout << "Success ✅" << std::endl;
    } catch (vt::assertion_failure const& e) {
      std::cout << "Failure ❌" << std::endl;
      std::cerr << e.what() << '\n';
    }
  };
  
  static constexpr auto test_all = [] (auto all) {
    const auto line = std::string(60, '=');
    std::cout << line << "\nClass Argument:\n" << line << std::endl;
    std::for_each(std::begin(all), std::end(all), TestCase::run);
  };
};

using TestCases = std::initializer_list<TestCase>;
} namespace vt = viraltaco_;
#endif  // VT_ARGUMENTATIVETEST_TESTS_TESTCASE_HPP_