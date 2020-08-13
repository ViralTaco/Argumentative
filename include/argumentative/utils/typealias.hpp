#ifndef VT_TYPEALIAS_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ typealias.hpp:                                       ┃
// ┃ Copyright (c) 2020 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                         ┃ 
// ┃ SPDX-License-Identifier: MIT                         ┃
// ┃ <http://www.opensource.org/licenses/MIT>             ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_TYPEALIAS_HPP "1.3.1"

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

namespace argumentative {
inline namespace typealias {
  // MARK: Integers
  using SizeType = std::size_t;
  using UInt = std::uint_fast64_t;
  using Int = std::int_fast64_t;
  using Char = char;
  using Byte = unsigned char;

  // MARK: Containers
  template <class T> using InitList = std::initializer_list<T>;
  template <class T> using Vector = std::vector<T>;
  template <class KeyType, class ValueType>
    using Map = std::unordered_map<KeyType, ValueType>;

  // MARK: Strings
  using String = std::basic_string<Char>;
  using StringView = std::basic_string_view<Char>;
  using CString = char const*;

  // MARK: Streams
  using StringStream = std::stringstream;

  // MARK: Functions
  template <class R, class... ArgTypes>
    using Function = std::function<R(ArgTypes...)>;
  using Functor = Function<void>;

  // MARK: Pointers
  template <class T> using Ptr = std::unique_ptr<T>;

  static constexpr auto newline = "\r\n";
} // inline namespace typealias
} namespace ive = argumentative;

#endif
