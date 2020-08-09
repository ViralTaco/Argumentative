#ifndef VT_HELP_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ Help.hpp:                                            ┃
// ┃ Copyright (c) 2020 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                         ┃ 
// ┃ SPDX-License-Identifier: MIT                         ┃
// ┃ <http://www.opensource.org/licenses/MIT>             ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_HELP_HPP "1.0.2"

#include "Argument.hpp"

namespace viraltaco_ {

struct Help : public Argument {
  [[maybe_unused]] explicit Help(StringView help) noexcept
      : Argument{ ArgKind::help, "help", help }
    {}
};

} namespace vt = viraltaco_;
#endif
