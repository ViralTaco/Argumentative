#include "TestArgument.hpp"
#include "TestInvalidOption.hpp"

int main() {
  constexpr auto const& test_all = vt::TestCase::test_all;
  test_all(argument_tests::all, "Argument");
  test_all(invalid_option_test::all, "InvalidOption");
}