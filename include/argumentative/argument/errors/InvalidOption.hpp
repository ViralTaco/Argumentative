#pragma once
#ifndef VT_INVALID_OPTION_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ InvalidOption.hpp:                                        ┃
// ┃ Copyright (c) 2020, 2026 viraltaco_ (viraltaco@gmx.com)   ┃
// ┃ https://github.com/ViralTaco                              ┃
// ┃ SPDX-License-Identifier: MIT                              ┃
// ┃ <http://www.opensource.org/licenses/MIT>                  ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_INVALID_OPTION_HPP "3.0.0"

// Standard Library
#include <exception>
#include <string>
#include <sstream>

// Internal
#include "../../utils/typealias.hpp"

namespace argumentative::inline v3_0_0 {

class [[maybe_unused]] invalid_option: public std::exception {
protected: // MARK: member
  static constexpr auto kFmt = [] (const auto s) {
    auto fmt = string_stream();
    fmt << "Option " << s << " wasn't provided with an argument.";
    return fmt.str();
  };
  string msg_;
  
public: // MARK: init
  explicit invalid_option(string_view opt_name) noexcept
    : msg_{ kFmt(opt_name) }
  {}
  
public: // MARK: instance methods
  [[nodiscard]] auto what() const noexcept -> char const* override {
    return msg_.c_str();
  }
};

} // namespace argumentative::inline v3_0_0
#endif
