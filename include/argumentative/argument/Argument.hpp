#pragma once
#ifndef VT_ARGUMENT_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ Argument.hpp:                                              ┃
// ┃ Copyright (c) 2020, 2026 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                               ┃ 
// ┃ SPDX-License-Identifier: MIT                               ┃
// ┃ <http://www.opensource.org/licenses/MIT>                   ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_ARGUMENT_HPP "3.1.0"

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

namespace argumentative::inline v3_1_0 {
enum class arg_kind {
  version,
  option,
  flag,
  help
};

struct argument {
public: // MARK: aliases
  using self = argument;
  
public: // MARK: constants
  static constexpr auto kTag = "--";
  
private: // MARK: members
  arg_kind kind_;
  string name_;
  string_view help_;
  string description_;
  
  string value_;
  bool seen_ = false;
  
public: // MARK: getters
  [[nodiscard]] constexpr auto kind() const noexcept -> arg_kind { return kind_; }
  [[nodiscard]] auto name() const noexcept -> string const& { return name_; }
  [[nodiscard]] constexpr auto help() const noexcept -> string_view { return help_; }
  [[nodiscard]] auto description() const noexcept -> string const& { return description_; }
  [[nodiscard]] auto value() const noexcept -> string const& { return value_; }
  [[nodiscard]] constexpr auto seen() const noexcept -> bool { return seen_; }
  
public: // MARK: init
  argument(arg_kind arg_kind, string_view arg_name, string_view arg_help) noexcept
    : kind_{ arg_kind }
    , name_{ string(kTag).append(arg_name) }
    , help_{ arg_help }
    , description_{ this->to_string() }
    , value_{ }
    , seen_{ arg_kind == arg_kind::help or arg_kind == arg_kind::version }
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
    str << '[' << name_;
    
    switch (kind_) {
    case arg_kind::option:
      str << " <" << name_.substr(2) << ">]";
      break;
    default:
      str << ']';
      break;
    }
    return str.str();
  }
  
  auto in(vector<string_view> const& argv) -> bool {
    const auto end = std::end(argv);
    auto arg = std::find(std::begin(argv), end, this->name_);

    if (not (this->seen_ = arg != end)) {
      return false;
    } else if (kind_ == arg_kind::option) {
      if ((++arg) != end) {
        this->value_ = *arg;
      } else {
        throw invalid_option(name_);
      }
    }
    return this->seen_;
  }

public: // MARK: operator overloads
  explicit operator bool() const noexcept {
    return seen_;
  }

  auto operator =(string const& arg_str) -> argument& {
    value_ = arg_str;
    return *this;
  }

  [[nodiscard]] auto operator ==(string_view rhs) const noexcept -> bool {
    return name_ == rhs;
  }

  [[nodiscard]] auto operator ==(argument const& rhs) const noexcept -> bool {
    return name_ == rhs.name_;
  }

public: // MARK: friend operator overloads
  friend auto operator <<(std::ostream& out, self const& self) noexcept -> std::ostream& {
    const auto padding = 20 - self.name_.length();
    return out << self.name_  << std::setw((padding > 0) ? padding : 1)
               << std::right << '\t' << self.help_;
  }
};

} // namespace argumentative::inline v3_1_0
#endif
