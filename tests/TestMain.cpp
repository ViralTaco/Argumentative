#include "TestArgument.hpp"
#include "TestInvalidOption.hpp"

auto main() -> int {
  constexpr auto const& test_all = vt::test_case::test_all;
  test_all(argument_tests::all, "argument");
  test_all(invalid_option_test::all, "invalid_option");
}