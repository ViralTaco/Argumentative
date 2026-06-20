#pragma once
#ifndef VT_ARGUMENT_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ Argument.hpp:                                              ┃
// ┃ Copyright (c) 2020, 2026 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                               ┃ 
// ┃ SPDX-License-Identifier: MIT                               ┃
// ┃ <http://www.opensource.org/licenses/MIT>                   ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_ARGUMENT_HPP "3.0.0"

// Standard Library
#include <string_view>
#include <string>
#include <iostream>
#include <iomanip>
#include <utility>
#include <algorithm>

// Internal
#include "../utils/typealias.hpp"
#include "../utils/swap_sign.hpp"
#include "errors/InvalidOption.hpp"

namespace argumentative::inline v3_0_0 {
enum class arg_kind {
  version,
  option,
  flag,
  help
};

struct argument {
public: // MARK: aliases
  using self = argument;
  
public: // MARK: members
  static constexpr auto kTag = "--";
  arg_kind kind;
  string name;
  string_view help;
  string description;
  
  string value;
  bool seen = false;
  
public: // MARK: init
  argument(arg_kind kind, string_view name, string_view help) noexcept
    : kind{ kind }
    , name{ string(kTag).append(name) }
    , help{ help }
    , description{ this->to_string() }
    , value{ }
    , seen{ kind == arg_kind::help or kind == arg_kind::version }
  {}
  
  argument(string_view name, string_view help) noexcept
    : argument{ arg_kind::flag, name, help }
  {}
  
  argument() noexcept = delete;
  argument(self const&) noexcept = default;
  argument(self&&) noexcept = default;
  
  auto operator =(self const&) noexcept -> argument& = default;
  
  virtual ~argument() = default;

public: // MARK: instance methods
  [[nodiscard]] auto to_string() const -> string {
    auto str = string_stream();
    str << '[' << name;
    
    switch (kind) {
    case arg_kind::option:
      str << " <" << name.substr(2) << ">]";
      break;
    default:
      str << ']';
      break;
    }
    return str.str();
  }
  
  auto in(vector<string_view> const& argv) -> bool {
    const auto end = std::end(argv);
    auto arg = std::find(std::begin(argv), end, this->name);

    if (not (this->seen = arg != end)) {
      return false;
    } else if (kind == arg_kind::option) {
      if ((++arg) != end) {
        this->value = *arg;
      } else {
        throw invalid_option(name);
      }
    }
    return this->seen;
  }

public: // MARK: operator overloads
  explicit operator bool() const noexcept {
    return seen;
  }

  auto operator =(string const& arg_str) -> argument& {
    value = arg_str;
    return *this;
  }

  [[nodiscard]] auto operator ==(string_view rhs) const noexcept -> bool {
    return name == rhs;
  }

  [[nodiscard]] auto operator ==(argument const& rhs) const noexcept -> bool {
    return name == rhs.name;
  }

public: // MARK: friend operator overloads
  friend auto operator <<(std::ostream& out, self const& self) noexcept -> std::ostream& {
    const auto padding = 20 - self.name.length();
    return out << self.name  << std::setw((padding > 0) ? padding : 1)
               << std::right << '\t' << self.help;
  }
};

} // namespace argumentative::inline v3_0_0
#endif
