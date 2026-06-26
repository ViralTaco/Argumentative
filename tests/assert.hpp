#pragma once
#ifndef VT_ASSERT_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ assert.hpp:                                                ┃
// ┃ Copyright (c) 2020, 2026 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                               ┃
// ┃ SPDX-License-Identifier: MIT                               ┃
// ┃ <http://www.opensource.org/licenses/MIT>                   ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_ASSERT_HPP "3.1.0"

#include <stdexcept>
#include <string>

namespace viraltaco_::inline v3_1_0 {
struct assertion_failure : public std::runtime_error {
  using std::runtime_error::runtime_error;
};

[[maybe_unused]] auto assert_impl(
    const bool b,
    std::string const& assertion,
    std::string const& func_name,
    std::string const& file_name,
    std::string const& line
    ) noexcept(false) -> void {
  if (b) {
    // assertion success
  } else {
    using namespace std::literals;
    throw assertion_failure("Assertion failed: '"s + assertion + "'\n"s +
        "In file: '"s + file_name + "'\n"s +
        "On line: "s + line + "\n"s +
        "In function: '"s + func_name + "()'\n"s
    );
  }
}
} // namespace viraltaco_::inline v3_1_0

namespace vt = viraltaco_;

#define assert_impl_(e, f, F, l) \
  viraltaco_::assert_impl(e, #e, f, F, std::to_string(l))
#define assert_true_(e, file)                                                  \
  ((void) ((e) ? ((void)0)                                                     \
  : assert_impl_(e, __PRETTY_FUNCTION__, file, __LINE__)))
#ifndef __clang__
#  define assert_true(e) assert_true_(e, __FILE__)
#else
#  define assert_true(e) assert_true_(e, __FILE_NAME__)
#endif
#define assert_false(e) assert_true(not (e))
#define assert_equal(a, b) assert_true(((a) == (b)))

#endif  // VT_ASSERT_HPP
