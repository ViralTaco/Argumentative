#ifndef VT_HELP_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ Help.hpp:                                            ┃
// ┃ Copyright (c) 2020 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                         ┃ 
// ┃ SPDX-License-Identifier: MIT                         ┃
// ┃ <http://www.opensource.org/licenses/MIT>             ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_HELP_HPP "1.0.3"

#include "Argument.hpp"

namespace argumentative {

struct Help : public Argument {
  [[maybe_unused]] explicit Help(StringView help) noexcept
    : Argument{ ArgKind::help, "help", help }
  {}
  
  [[maybe_unused]] Help() noexcept
    : Help{ "Show help for this command." }
  {}
};

} namespace ive = argumentative;
#endif
