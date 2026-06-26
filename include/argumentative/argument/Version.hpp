#pragma once
#ifndef VT_VERSION_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ Version.hpp:                                              ┃
// ┃ Copyright (c) 2020, 2026 viraltaco_ (viraltaco@gmx.com)   ┃
// ┃ https://github.com/ViralTaco                              ┃
// ┃ SPDX-License-Identifier: MIT                              ┃
// ┃ <http://www.opensource.org/licenses/MIT>                  ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_VERSION_HPP "3.1.0"

// Standard Library
#include <utility>

// Internal
#include "Argument.hpp"

namespace argumentative::inline v3_1_0 {
struct version : public argument {
  [[maybe_unused]] explicit version(string version_str) noexcept
    : argument{ arg_kind::version, "version",
                "Show the version of this application." }
  { argument::operator=(std::move(version_str)); }
};

} // namespace argumentative::inline v3_1_0
#endif
