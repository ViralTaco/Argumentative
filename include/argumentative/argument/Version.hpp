#ifndef VT_VERSION_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ Version.hpp:                                         ┃
// ┃ Copyright (c) 2020 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                         ┃ 
// ┃ SPDX-License-Identifier: MIT                         ┃
// ┃ <http://www.opensource.org/licenses/MIT>             ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_VERSION_HPP "1.1.0"

#include <utility>
#include "Argument.hpp"

namespace argumentative {
struct Version : public Argument {
  [[maybe_unused]] explicit Version(String version) noexcept
    : Argument{ ArgKind::version, "version",
                "Show the version of this application." }
  { this->value = std::move(version); }
};

} namespace ive = argumentative;
#endif
