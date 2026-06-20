#pragma once
#ifndef VT_ARGUMENTATIVETEST_TESTS_TESTCASE_HPP_
#define VT_ARGUMENTATIVETEST_TESTS_TESTCASE_HPP_ "3.0.0"

#include "assert.hpp"

#include <initializer_list>
#include <string_view>
#include <ios>
#include <iostream>
#include <iomanip>
#include <algorithm>

namespace viraltaco_::inline v3_0_0 {
class test_case {
public: // alias
  using lambda_type = void(*)();
  
private: // members
  std::string_view test_str_;
  lambda_type test_;
  
public: // inits
  constexpr test_case(std::string_view test_str, lambda_type test) noexcept
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
  
  static constexpr auto test_all = [] (auto all, auto class_name) {
    const auto line = std::string(60, '=');
    std::cout << line
              << "\nClass " << class_name << ":\n"
              << line << std::endl;
    std::ranges::for_each(all, test_case::run);
  };
};

using test_cases = std::initializer_list<test_case>;
} // namespace viraltaco_::inline v3_0_0

namespace vt = viraltaco_;
#endif  // VT_ARGUMENTATIVETEST_TESTS_TESTCASE_HPP_