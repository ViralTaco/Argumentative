#ifndef VT_ARGUMENT_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ Argument.hpp:                                        ┃
// ┃ Copyright (c) 2020 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                         ┃ 
// ┃ SPDX-License-Identifier: MIT                         ┃
// ┃ <http://www.opensource.org/licenses/MIT>             ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_ARGUMENT_HPP "2.1.0"

#include "../utils/typealias.hpp"
#include "../utils/swap_sign.hpp"
#include "errors/InvalidOption.hpp"

#include <string_view>
#include <string>
#include <iostream>
#include <utility>

#include <algorithm>

namespace viraltaco_ {
enum class ArgKind {
  option,
  flag,
  help
};

struct Argument {
public: // MARK: aliases
  using Self = Argument;

protected: // MARK: Polymorphism be damned.
  ArgKind kind_ = ArgKind::flag;
  static constexpr auto kTag = "--";

public: // MARK: members
#define VT_PADDING(qty, name) [[maybe_unused, gnu::visibility("hidden")]] Byte p_##name[qty]{}
  VT_PADDING(4, name);
  String name;
  StringView help;
  String description;
  
  String value;
  bool seen = false;
  VT_PADDING(7, seen);
#undef VT_PADDING

public: // MARK: init
  Argument(ArgKind kind, StringView name, StringView help) noexcept
    : kind_{ kind }
    , name{ String(kTag).append(name) }
    , help{ help }
    , description{ this->to_string() }
    , value{ }
    , seen{ kind == ArgKind::help }
  {}
  
  Argument(StringView name, StringView help) noexcept
    : Argument{ ArgKind::flag, name, help }
  {}
  
  Argument() noexcept = default;
  Argument(Self const&) noexcept = default;
  Argument(Self&&) = default;
  
  Argument& operator =(Self const&) noexcept = default;
  
  virtual ~Argument() = default;

public: // MARK: instance methods
  [[nodiscard]] String to_string() const {
    auto str = StringStream();
    str << '[' << name;
    
    switch (kind_) {
    case ArgKind::option:
      str << " <" << name.substr(2) << ">]";
      break;
    default:
      str << ']';
      break;
    }
    return str.str();
  }
  
  bool in(Vector<StringView> const& argv) {
    const auto end = std::end(argv);
    auto arg = std::find(std::begin(argv), end, this->name);

    if (not (this->seen = arg != end)) {
      return false;
    } else if (kind_ == ArgKind::option) {
      if ((++arg) != end) {
        this->value = *arg;
      } else {
        throw InvalidOption(name);
      }
    }
    return this->seen;
  }

public: // MARK: operator overloads
  explicit operator bool() const noexcept {
    return seen;
  }

  Argument& operator =(String const& arg) {
    value = arg;
    return *this;
  }

  bool operator ==(StringView rhs) const noexcept {
    return name == rhs;
  }

  bool operator ==(Argument const& rhs) const noexcept {
    return name == rhs.name;
  }

public: // MARK: friend operator overloads
  friend std::ostream&
  operator <<(std::ostream& out, Self const& self) noexcept {
    const auto len = self.name.length();
    
    if (len >= 20) {
      out << self.name << '\t';
    } else {
      out << self.name << String(20ull - len, ' ') << '\t';
    }
    return out << self.help;
  }
  
};

} namespace vt = viraltaco_;
#endif
