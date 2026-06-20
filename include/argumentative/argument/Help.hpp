#pragma once
#ifndef VT_HELP_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ Help.hpp:                                                 ┃
// ┃ Copyright (c) 2020, 2026 viraltaco_ (viraltaco@gmx.com)   ┃
// ┃ https://github.com/ViralTaco                              ┃
// ┃ SPDX-License-Identifier: MIT                              ┃
// ┃ <http://www.opensource.org/licenses/MIT>                  ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_HELP_HPP "3.0.0"

// Internal
#include "Argument.hpp"

namespace argumentative::inline v3_0_0 {

struct help : public argument {
  [[maybe_unused]] explicit help(string_view help_str) noexcept
    : argument{ arg_kind::help, "help", help_str }
  {}
  
  [[maybe_unused]] help() noexcept
    : help{ "Show help for this application." }
  {}
};

} // namespace argumentative::inline v3_0_0
#endif
