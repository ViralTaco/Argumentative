#ifndef VT_TEST_ARGUMENT_HPP
#define VT_TEST_ARGUMENT_HPP "1.0.1"

#include <string_view>
#include <initializer_list>
#include <stdexcept>

#include "../include/argumentative/utils/typealias.hpp"
#include "TestCase.hpp"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wkeyword-macro"
// This is evil but it makes testing easier:
#define protected public
#define private public
#include "../include/argumentative/argument/Argument.hpp"
#undef private
#undef protected
#pragma clang diagnostic pop

namespace argument_tests {
using namespace argumentative;
using namespace std::literals;

inline namespace placeholders {
  static constexpr auto sv__1 = "name"sv;
  static constexpr auto sv__1_flag = "--name"sv;
  static constexpr auto sv__2 = "help"sv;
  static constexpr auto sv__3 = "anything else"sv;
}

static constexpr auto test_init = [] () {
  const auto expected_name = "--"s + std::string(sv__1);
  auto arg = Argument(sv__1, sv__2);
  assert_equal(arg.kind, ArgKind::flag);
  assert_equal(arg.name, expected_name);
  assert_equal(arg.help, sv__2);
  assert_equal(arg.description, "[--"s + String(sv__1) + "]"s);
  assert_false(arg.seen);
};

static constexpr auto test_to_string = [] () {
  auto arg = Argument(sv__1, sv__2);
  assert_equal(arg.kind, ArgKind::flag);
  assert_true(arg.to_string() == "[--"s + String(sv__1) + "]"s);
};

static constexpr auto test_in = [] () {
  auto arg = Argument(sv__1, sv__2);
  const auto flag = std::string(Argument::kTag) + std::string(sv__1);
  auto argv = std::vector<std::string_view>();
  argv.push_back(std::string_view(flag));
  assert_true(arg.in(argv));
  assert_true(arg.seen);
};

static constexpr auto test_operator_eq = [] () {
  auto arg = Argument(sv__1, sv__2);
  arg = ive::String(sv__3);
  assert_equal(sv__3, arg.value);
};

static constexpr auto test_is_eq_sv = [] () {
  auto arg = Argument(sv__1, sv__2);
  auto arh = Argument(sv__1, sv__3);
  assert_true(arg.operator==(sv__1_flag));
  assert_true(arh.operator==(sv__1_flag));
};

static constexpr auto test_is_eq = [] () {
  auto arg = Argument(sv__1, sv__2);
  auto arh = Argument(sv__1, sv__3);
  assert_equal(arg, arh);
};

[[maybe_unused]] const vt::TestCases all{
   { "constructor"sv,     test_init        },
   { "to_string()"sv,     test_to_string   },
   { "in()"sv,            test_in          },
   { "=(String)"sv,       test_operator_eq },
   { "==(StringView)"sv,  test_is_eq_sv    },
   { "==(Argument)"sv,    test_is_eq       },
};
} // namespace argumentative_tests

#endif // not defined (VT_TEST_ARGUMENT_HPP)
