#pragma once
#ifndef VT_SWAP_SIGN_HPP
#define VT_SWAP_SIGN_HPP

// Standard Library
#include <type_traits>

namespace argumentative::inline v3_1_0 {

  template <class T>
  [[nodiscard]] constexpr auto swap_sign(const T integral) noexcept -> auto {
    if constexpr (std::is_unsigned_v<T>) {
      return static_cast<std::make_signed_t<T>>(integral);
    } else {
      return static_cast<std::make_unsigned_t<T>>(integral);
    }
  }

} // namespace argumentative::inline v3_1_0

#endif // VT_SWAP_SIGN_HPP
