#pragma once
#ifndef ARGUMENTATIVE_TESTS_TESTINVALIDOPTION_HPP_
#define ARGUMENTATIVE_TESTS_TESTINVALIDOPTION_HPP_ "3.0.0"

#include <string_view>
#include <string>
#include <algorithm>
#include <ranges>

#include "../include/argumentative/argument/errors/InvalidOption.hpp"
#include "TestCase.hpp"

namespace invalid_option_test::inline v3_0_0 {
using namespace argumentative;
using namespace std::literals;

inline namespace placeholders {
  static constexpr auto kSvs = {
    "Some Option"sv,
    "Some other Option"sv,
    "Really trying my luck"sv,
    "More shit"sv,
  };
} // inline namespace placeholders

static constexpr auto test_throw = [] {
  std::ranges::for_each(kSvs, [] (auto s) {
    const auto what_str =
      "Option "s + std::string(s) + " wasn't provided with an argument."s;
    try {
      throw invalid_option(s);
    } catch (invalid_option const& e) {
      assert_true(std::string(e.what()) == what_str);
    }
  });
};

constexpr vt::test_cases all {
  { "test_what()", test_throw }
};
} // namespace invalid_option_test::inline v3_0_0

#endif // ARGUMENTATIVE_TESTS_TESTINVALIDOPTION_HPP_
