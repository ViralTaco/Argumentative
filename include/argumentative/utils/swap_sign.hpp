#ifndef VT_SWAP_SIGN_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ swap_sign.hpp:                                             ┃
// ┃ Copyright (c) 2020, 2026 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                               ┃
// ┃ SPDX-License-Identifier: MIT                               ┃
// ┃ <http://www.opensource.org/licenses/MIT>                   ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_SWAP_SIGN_HPP "1.1.0"

#include <type_traits>

namespace argumentative {
 inline namespace v1 { /// MARK: - v1
    template <class T> [[nodiscard, maybe_unused]]
    constexpr auto swap_sign(const T integral) noexcept {
      if constexpr (std::is_unsigned_v<T>) { // unsigned --> signed
        return static_cast< std::make_signed_t<T> > (integral);
      } else {                               // signed --> unsigned
      return static_cast< std::make_unsigned_t<T> > (integral);
    }
  }
 } // argumentative::inline v1
} // namespace argumentative
namespace ive = argumentative::v2;
#endif
