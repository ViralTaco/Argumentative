#pragma once
#ifndef VT_TYPEALIAS_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ typealias.hpp:                                            ┃
// ┃ Copyright (c) 2020, 2026 viraltaco_ (viraltaco@gmx.com)   ┃
// ┃ https://github.com/ViralTaco                              ┃
// ┃ SPDX-License-Identifier: MIT                              ┃
// ┃ <http://www.opensource.org/licenses/MIT>                  ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_TYPEALIAS_HPP "3.1.0"

// Standard Library
#include <initializer_list>
#include <unordered_map>
#include <vector>
#include <string>
#include <string_view>
#include <sstream>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <functional>

namespace argumentative::inline v3_1_0 {
inline namespace typealias {
  // MARK: Integers
  using size_type = std::size_t;
  using uint_type = std::uint_fast64_t;
  using int_type = std::int_fast64_t;
  using char_type = char;
  using byte_type = unsigned char;

  // MARK: Containers
  template <class T> using init_list = std::initializer_list<T>;
  template <class T> using vector = std::vector<T>;
  template <class KeyType, class ValueType>
    using map = std::unordered_map<KeyType, ValueType>;

  // MARK: Strings
  using string = std::basic_string<char_type>;
  using string_view = std::basic_string_view<char_type>;
  using c_string = char const*;

  // MARK: Streams
  using string_stream = std::stringstream;

  // MARK: Functions
  template <class R, class... ArgTypes>
    using function = std::function<R(ArgTypes...)>;
  using functor = function<void>;

  // MARK: Pointers
  template <class T> using ptr = std::unique_ptr<T>;

  static constexpr auto kNewline = "\r\n";
} // inline namespace typealias
} // namespace argumentative::inline v3_1_0

#endif
