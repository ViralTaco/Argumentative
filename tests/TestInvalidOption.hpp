#ifndef ARGUMENTATIVE_TESTS_TESTINVALIDOPTION_HPP_
#define ARGUMENTATIVE_TESTS_TESTINVALIDOPTION_HPP_ "1.0.0"

#include <string_view>
#include <string>
#include <algorithm>

#include "../include/argumentative/argument/errors/InvalidOption.hpp"
#include "TestCase.hpp"

namespace invalid_option_test {
using namespace ive;
using namespace std::literals;

inline namespace placeholders {
  static constexpr auto svs__ = {
    "Some Option"sv,
    "Some other Option"sv,
    "Really trying my luck"sv,
    "More shit"sv,
  };
} // inline namespace placeholders

static constexpr auto test_throw = [] {
  std::for_each(svs__.begin(), svs__.end(), [] (auto s) {
    const auto what_str =
      "Option "s + std::string(s) + " wasn't provided with an argument."s;
    try {
      throw InvalidOption(s);
    } catch (InvalidOption const& e) {
      assert_true(std::string(e.what()) == what_str);
    }
  });
};

constexpr vt::TestCases all {
  { "test_what()", test_throw }
};
} // namespace invalid_option_test

#endif //ARGUMENTATIVE_TESTS_TESTINVALIDOPTION_HPP_
