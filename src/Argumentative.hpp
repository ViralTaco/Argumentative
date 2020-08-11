#ifndef VT_ARGUMENTATIVE_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ Argumentative.hpp:                                   ┃
// ┃ Copyright (c) 2020 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                         ┃ 
// ┃ SPDX-License-Identifier: MIT                         ┃
// ┃ <http://www.opensource.org/licenses/MIT>             ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_ARGUMENTATIVE_HPP "1.3.2"

#include "utils/typealias.hpp"
#include "argument/*.hpp"

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

namespace argumentative {
class Argumentative {
public: // MARK: aliases
  using Self = Argumentative;
  using ArgVec = Vector<Argument>;
  
private: // MARK: members
  Vector<StringView> argv_;
  ArgVec args_;
  ArgVec matches_;
  
  StringView app_name_;
  String app_version_;
  
public: // MARK: init
  [[maybe_unused]] Argumentative(const int argc, char** argv)
    : argv_{ argv, argv + argc }
    , args_{ }
    , matches_{ }
    , app_name_{ Self::app_name(argv_[0]) }
    , app_version_{}
  {}
  
  [[maybe_unused]] Argumentative(const int argc, char** argv,
                                 InitList<Argument> args)
    : argv_{ argv, argv + argc }
    , args_{ args.begin(), args.end() }
    , matches_{ Self::matches(args_, argv_) }
    , app_name_{ Self::app_name(argv_[0]) }
    , app_version_{}
  {}
  
  // MARK: rule of five
  Argumentative() noexcept = default;
  Argumentative(Self&&) noexcept = default;
  Argumentative(Self const&) noexcept = default;
  Argumentative& operator =(Self const&) noexcept = default;
  
  virtual ~Argumentative() noexcept = default;
  
public: // MARK: class methods
  static constexpr StringView app_name(StringView prog_path) noexcept {
    return prog_path.substr(prog_path.rfind('/') + 1u);
  }
  
  static ArgVec matches(ArgVec& args, Vector<StringView> const& argv) noexcept {
    auto matches = ArgVec();
    std::copy_if(std::begin(args), std::end(args),           // Source
                 std::back_inserter(matches),                // Destination
                 [&](auto& arg) { return arg.in(argv); }) ;  // Predicate
    return matches;
  }
  
public: // MARK: instance methods
  Self& append(InitList<Argument> const& args) {
    for (auto const& arg: args) { // Making a copy.
      this->append(arg);
    }
    return *this;
  }
  
  Self& append(Argument arg) {
    args_.push_back(arg);
    if (arg.kind == ArgKind::version) {
      app_version_ = arg.value;
    }
    if (arg.in(argv_)) {
      matches_.push_back(arg);
    }
    return *this;
  }
  
  [[nodiscard]] String usage() const noexcept {
    auto usage = StringStream();
    usage << "Usage: " << app_name_ << ' ';
    
    for (auto const& arg: args_) {
      usage << arg.description << ' ';
    }
    
    usage << newline;
    for (auto const& arg: args_) {
      usage << newline << arg;
    }
    
    return usage.str();
  }
  
  [[nodiscard, maybe_unused]] String version() const noexcept {
    auto version = StringStream();
    version << app_name_ << ' ' << app_version_ << newline;
    return version.str();
  }
  
public: // MARK: operator overloads
  auto operator +=(InitList<Argument> const& args) {
    return this->append(args);
  }
  
  auto operator +=(Argument const& arg) {
    return this->append(arg);
  }
  
  auto operator <<(Argument const& rhs) {
    return this->append(rhs);
  }
  
public: // MARK: friend operator overloads
  friend std::ostream& operator <<(std::ostream& out, Self const& self) {
    return out << self.usage();
  }
  
public: // MARK: constraint 'Container'
  [[nodiscard, maybe_unused]] auto empty() const noexcept {
    return matches_.empty();
  }
  
  [[maybe_unused]] auto begin() noexcept {
    return matches_.begin();
  }
  
  [[nodiscard, maybe_unused]] auto cbegin() const noexcept {
    return const_cast<ArgVec const&> (matches_).begin();
  }
  
  [[maybe_unused]] auto rbegin() noexcept {
    return matches_.rbegin();
  }
  
  [[nodiscard, maybe_unused]] auto crbegin() const noexcept {
    return const_cast<ArgVec const&> (matches_).rbegin();
  }
  
  [[maybe_unused]] auto end() noexcept {
    return matches_.end();
  }
  
  [[nodiscard, maybe_unused]] auto cend() const noexcept {
    return const_cast<ArgVec const&> (matches_).end();
  }
  
  [[maybe_unused]] auto rend() noexcept {
    return matches_.rend();
  }
  
  [[nodiscard, maybe_unused]] auto crend() const noexcept {
    return const_cast<ArgVec const&> (matches_).rend();
  }
};

} namespace ive = argumentative;
#endif
