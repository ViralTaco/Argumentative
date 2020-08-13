#ifndef VT_OPTION_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ Option.hpp:                                          ┃
// ┃ Copyright (c) 2020 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                         ┃ 
// ┃ SPDX-License-Identifier: MIT                         ┃
// ┃ <http://www.opensource.org/licenses/MIT>             ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_OPTION_HPP "7.2.0"

#include "../utils/typealias.hpp"
#include "errors/InvalidOption.hpp"
#include "Argument.hpp"

#include <string_view>
#include <utility>

namespace argumentative {
/**
 * This structure hold a name and the help message.
 * If it is equal to one of the arguments parsed at runtime
 * then an object containing a reference to it and the corresponding argument
 */
struct Option: public Argument {
public: // MARK: init
  [[maybe_unused]] Option(StringView name, StringView help) noexcept
    : Argument{ ArgKind::option, name, help }
  {}
};

} namespace ive = argumentative;
#endif
