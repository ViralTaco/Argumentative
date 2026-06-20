#pragma once
#ifndef VT_FLAG_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ Flag.hpp:                                                 ┃
// ┃ Copyright (c) 2020, 2026 viraltaco_ (viraltaco@gmx.com)   ┃
// ┃ https://github.com/ViralTaco                              ┃
// ┃ SPDX-License-Identifier: MIT                              ┃
// ┃ <http://www.opensource.org/licenses/MIT>                  ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_FLAG_HPP "3.0.0"

// Internal
#include "Argument.hpp"

namespace argumentative::inline v3_0_0 {

struct flag: public argument {
  using argument::argument;
};

} // namespace argumentative::inline v3_0_0
#endif
