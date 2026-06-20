#pragma once
#ifndef VT_OPTION_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ Option.hpp:                                               ┃
// ┃ Copyright (c) 2020, 2026 viraltaco_ (viraltaco@gmx.com)   ┃
// ┃ https://github.com/ViralTaco                              ┃
// ┃ SPDX-License-Identifier: MIT                              ┃
// ┃ <http://www.opensource.org/licenses/MIT>                  ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_OPTION_HPP "3.0.0"

// Standard Library
#include <string_view>
#include <utility>

// Internal
#include "../utils/typealias.hpp"
#include "errors/InvalidOption.hpp"
#include "Argument.hpp"

namespace argumentative::inline v3_0_0 {
/**
 * This structure hold a name and the help message.
 * If it is equal to one of the arguments parsed at runtime
 * then an object containing a reference to it and the corresponding argument
 */
struct option: public argument {
public: // MARK: init
  [[maybe_unused]] option(string_view name, string_view help) noexcept
    : argument{ arg_kind::option, name, help }
  {}
};

} // namespace argumentative::inline v3_0_0
#endif
