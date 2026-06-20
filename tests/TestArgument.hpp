#pragma once
#ifndef VT_TEST_ARGUMENT_HPP
#define VT_TEST_ARGUMENT_HPP "3.0.0"

#include <string_view>
#include <initializer_list>
#include <stdexcept>
#include <string>

#include "../include/argumentative/utils/typealias.hpp"
#include "TestCase.hpp"

#include "../include/argumentative/argument/Argument.hpp"

namespace argument_tests::inline v3_0_0 {
using namespace argumentative;
using namespace std::literals;

inline namespace placeholders {
  static constexpr auto kSv1 = "name"sv;
  static constexpr auto kSv1Flag = "--name"sv;
  static constexpr auto kSv2 = "help"sv;
  static constexpr auto kSv3 = "anything else"sv;
}

static constexpr auto test_init = [] () {
  const auto expected_name = "--"s + std::string(kSv1);
  auto arg = argument(kSv1, kSv2);
  assert_equal(arg.kind, arg_kind::flag);
  assert_equal(arg.name, expected_name);
  assert_equal(arg.help, kSv2);
  assert_equal(arg.description, "[--"s + string(kSv1) + "]"s);
  assert_false(arg.seen);
};

static constexpr auto test_to_string = [] () {
  auto arg = argument(kSv1, kSv2);
  assert_equal(arg.kind, arg_kind::flag);
  assert_true(arg.to_string() == "[--"s + string(kSv1) + "]"s);
};

static constexpr auto test_in = [] () {
  auto arg = argument(kSv1, kSv2);
  const auto flag = std::string(argument::kTag) + std::string(kSv1);
  auto argv = std::vector<std::string_view>();
  argv.push_back(std::string_view(flag));
  assert_true(arg.in(argv));
  assert_true(arg.seen);
};

static constexpr auto test_operator_eq = [] () {
  auto arg = argument(kSv1, kSv2);
  arg = ::argumentative::string(kSv3);
  assert_equal(kSv3, arg.value);
};

static constexpr auto test_is_eq_sv = [] () {
  auto arg = argument(kSv1, kSv2);
  auto arh = argument(kSv1, kSv3);
  assert_true(arg.operator==(kSv1Flag));
  assert_true(arh.operator==(kSv1Flag));
};

static constexpr auto test_is_eq = [] () {
  auto arg = argument(kSv1, kSv2);
  auto arh = argument(kSv1, kSv3);
  assert_equal(arg, arh);
};

[[maybe_unused]] const vt::test_cases all{
   { "constructor"sv,     test_init        },
   { "to_string()"sv,     test_to_string   },
   { "in()"sv,            test_in          },
   { "=(String)"sv,       test_operator_eq },
   { "==(StringView)"sv,  test_is_eq_sv    },
   { "==(Argument)"sv,    test_is_eq       },
};
} // namespace argument_tests::inline v3_0_0

#endif // VT_TEST_ARGUMENT_HPP
