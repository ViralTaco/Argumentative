#ifndef VT_SWAP_SIGN_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ swap_sign.hpp:                                       ┃
// ┃ Copyright (c) 2020 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                         ┃
// ┃ SPDX-License-Identifier: MIT                         ┃
// ┃ <http://www.opensource.org/licenses/MIT>             ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_SWAP_SIGN_HPP "1.0.1"

#include <type_traits>

namespace argumentative {

template <class T> [[nodiscard, maybe_unused]]
constexpr auto swap_sign(const T integral) noexcept {
  if constexpr (std::is_unsigned_v<T>) { // unsigned --> signed
    return static_cast< std::make_signed_t<T> > (integral);
  } else {                               // signed --> unsigned
    return static_cast< std::make_unsigned_t<T> > (integral);
  }
}

} namespace ive = argumentative;

#endif
