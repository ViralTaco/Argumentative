#pragma once
#ifndef VT_ARGUMENTATIVE_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ Argumentative.hpp:                                        ┃
// ┃ Copyright (c) 2020, 2026 viraltaco_ (viraltaco@gmx.com)   ┃
// ┃ https://github.com/ViralTaco                              ┃
// ┃ SPDX-License-Identifier: MIT                              ┃
// ┃ <http://www.opensource.org/licenses/MIT>                  ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_ARGUMENTATIVE_HPP "3.0.0"

// Standard Library
#include <utility>   // std::move, std::forward
#include <iterator>  // std::back_inserter
#include <algorithm> // std::copy_if
#include <string>
#include <string_view>
#include <sstream>
#include <vector>
#include <initializer_list>
#include <cstdint>
#include <cstddef>
#include <ranges>

// Internal
#include "argumentative/utils/typealias.hpp"
#include "argumentative/argument/Argument.hpp"
#include "argumentative/argument/Flag.hpp"
#include "argumentative/argument/Option.hpp"
#include "argumentative/argument/Help.hpp"
#include "argumentative/argument/Version.hpp"

namespace argumentative::inline v3_0_0 {
class argumentative {
public: // MARK: aliases
  using self = argumentative;
  using arg_vec = vector<argument>;
  
private: // MARK: members
  alignas(64) vector<string_view> argv_;
  alignas(64) arg_vec args_;
  alignas(64) arg_vec matches_;
  
  string_view app_name_;
  string app_version_;
  
public: // MARK: init
  [[maybe_unused]] argumentative(const int argc, char** argv)
    : argv_{ argv, argv + argc }
    , args_{ }
    , matches_{ }
    , app_name_{ self::app_name(argv_[0]) }
    , app_version_{}
  {}
  
  [[maybe_unused]] argumentative(const int argc, char** argv,
                                 init_list<argument> args)
    : argv_{ argv, argv + argc }
    , args_{ args.begin(), args.end() }
    , matches_{ self::matches(args_, argv_) }
    , app_name_{ self::app_name(argv_[0]) }
    , app_version_{}
  {}
  
  // MARK: rule of five
  argumentative() noexcept = default;
  argumentative(self&&) noexcept = default;
  argumentative(self const&) noexcept = default;
  auto operator =(self const&) noexcept -> argumentative& = default;
  
  virtual ~argumentative() = default;
  
public: // MARK: class methods
  [[nodiscard]] static constexpr auto app_name(string_view prog_path) noexcept -> string_view {
    return prog_path.substr(prog_path.rfind('/') + 1zu);
  }
  
  [[nodiscard]] static auto matches(arg_vec& args, vector<string_view> const& argv) -> arg_vec {
    auto matches = arg_vec();
    
    for (auto& arg : args | std::views::filter([&](auto& a) { return a.in(argv); })) {
      matches.push_back(arg);
    }
    
    return matches;
  }
  
public: // MARK: instance methods
  auto append(init_list<argument> const& args) -> self& {
    for (auto const& arg: args) { // Making a copy.
      this->append(arg);
    }
    return *this;
  }
  
  auto append(argument arg) -> self& {
    args_.push_back(arg);
    if (arg.kind == arg_kind::version) {
      app_version_ = arg.value;
    }
    if (arg.in(argv_)) {
      matches_.push_back(arg);
    }
    return *this;
  }
  
  [[nodiscard]] auto usage() const -> string {
    auto usg = string_stream();
    usg << "Usage: " << app_name_ << ' ';
    
    for (auto const& arg: args_) {
      usg << arg.description << ' ';
    }
    
    usg << kNewline;
    for (auto const& arg: args_) {
      usg << kNewline << arg;
    }
    
    return usg.str();
  }
  
  [[nodiscard, maybe_unused]] auto version() const -> string {
    auto ver = string_stream();
    ver << app_name_ << ' ' << app_version_ << kNewline;
    return ver.str();
  }
  
public: // MARK: operator overloads
  auto operator +=(init_list<argument> const& args) -> auto {
    return this->append(args);
  }
  
  auto operator +=(argument const& arg) -> auto {
    return this->append(arg);
  }
  
  auto operator <<(argument const& rhs) -> auto {
    return this->append(rhs);
  }
  
public: // MARK: friend operator overloads
  friend auto operator <<(std::ostream& out, self const& self) -> std::ostream& {
    return out << self.usage();
  }
  
public: // MARK: constraint 'Container'
  [[nodiscard, maybe_unused]] auto empty() const noexcept -> bool {
    return matches_.empty();
  }
  
  [[maybe_unused]] auto begin() noexcept -> auto {
    return matches_.begin();
  }
  
  [[nodiscard, maybe_unused]] auto cbegin() const noexcept -> auto {
    return const_cast<arg_vec const&> (matches_).begin();
  }
  
  [[maybe_unused]] auto rbegin() noexcept -> auto {
    return matches_.rbegin();
  }
  
  [[nodiscard, maybe_unused]] auto crbegin() const noexcept -> auto {
    return const_cast<arg_vec const&> (matches_).rbegin();
  }
  
  [[maybe_unused]] auto end() noexcept -> auto {
    return matches_.end();
  }
  
  [[nodiscard, maybe_unused]] auto cend() const noexcept -> auto {
    return const_cast<arg_vec const&> (matches_).end();
  }
  
  [[maybe_unused]] auto rend() noexcept -> auto {
    return matches_.rend();
  }
  
  [[nodiscard, maybe_unused]] auto crend() const noexcept -> auto {
    return const_cast<arg_vec const&> (matches_).rend();
  }
};

} // namespace argumentative::inline v3_0_0
#endif
