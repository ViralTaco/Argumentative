#ifndef VT_ARGUMENTATIVE_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ Argumentative.hpp:                                   ┃
// ┃ Copyright (c) 2020 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                         ┃
// ┃ SPDX-License-Identifier: MIT                         ┃
// ┃ <http://www.opensource.org/licenses/MIT>             ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_ARGUMENTATIVE_HPP "1.3.1"

#ifndef VT_TYPEALIAS_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ typealias.hpp:                                       ┃
// ┃ Copyright (c) 2020 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                         ┃
// ┃ SPDX-License-Identifier: MIT                         ┃
// ┃ <http://www.opensource.org/licenses/MIT>             ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_TYPEALIAS_HPP "1.3.1"

#include <cstddef>
#include <cstdint>
#include <functional>
#include <initializer_list>
#include <memory>
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace argumentative {
inline namespace typealias {
// MARK: Integers
using SizeType = std::size_t;
using UInt = std::uint_fast64_t;
using Int = std::int_fast64_t;
using Char = char;
using Byte = unsigned char;

// MARK: Containers
template <class T>
using InitList = std::initializer_list<T>;
template <class T>
using Vector = std::vector<T>;
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
template <class T>
using Ptr = std::unique_ptr<T>;

static constexpr auto newline = "\r\n";
}  // namespace typealias
}  // namespace argumentative
namespace ive = argumentative;

#endif

#ifndef VT_ALL_HEADERS_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ *.hpp:                                               ┃
// ┃ Copyright (c) 2020 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                         ┃
// ┃ SPDX-License-Identifier: MIT                         ┃
// ┃ <http://www.opensource.org/licenses/MIT>             ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_ALL_HEADERS_HPP true
// This header is a shortcut to include all the classes in the 'argument'
// folder.

#ifndef VT_FLAG_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ Flag.hpp:                                            ┃
// ┃ Copyright (c) 2020 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                         ┃
// ┃ SPDX-License-Identifier: MIT                         ┃
// ┃ <http://www.opensource.org/licenses/MIT>             ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_FLAG_HPP "2.3.1"

#ifndef VT_ARGUMENT_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ Argument.hpp:                                        ┃
// ┃ Copyright (c) 2020 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                         ┃
// ┃ SPDX-License-Identifier: MIT                         ┃
// ┃ <http://www.opensource.org/licenses/MIT>             ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_ARGUMENT_HPP "2.1.0"

#ifndef VT_TYPEALIAS_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ typealias.hpp:                                       ┃
// ┃ Copyright (c) 2020 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                         ┃
// ┃ SPDX-License-Identifier: MIT                         ┃
// ┃ <http://www.opensource.org/licenses/MIT>             ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_TYPEALIAS_HPP "1.3.1"

#include <cstddef>
#include <cstdint>
#include <functional>
#include <initializer_list>
#include <memory>
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace argumentative {
inline namespace typealias {
// MARK: Integers
using SizeType = std::size_t;
using UInt = std::uint_fast64_t;
using Int = std::int_fast64_t;
using Char = char;
using Byte = unsigned char;

// MARK: Containers
template <class T>
using InitList = std::initializer_list<T>;
template <class T>
using Vector = std::vector<T>;
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
template <class T>
using Ptr = std::unique_ptr<T>;

static constexpr auto newline = "\r\n";
}  // namespace typealias
}  // namespace argumentative
namespace ive = argumentative;

#endif

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

template <class T>
[[nodiscard, maybe_unused]] constexpr auto swap_sign(
    const T integral) noexcept {
  if constexpr (std::is_unsigned_v<T>) {  // unsigned --> signed
    return static_cast<std::make_signed_t<T> >(integral);
  } else {  // signed --> unsigned
    return static_cast<std::make_unsigned_t<T> >(integral);
  }
}

}  // namespace argumentative
namespace ive = argumentative;

#endif

#ifndef VT_INVALID_OPTION_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ InvalidOption.hpp:                                   ┃
// ┃ Copyright (c) 2020 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                         ┃
// ┃ SPDX-License-Identifier: MIT                         ┃
// ┃ <http://www.opensource.org/licenses/MIT>             ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_INVALID_OPTION_HPP "1.0.0"

#ifndef VT_TYPEALIAS_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ typealias.hpp:                                       ┃
// ┃ Copyright (c) 2020 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                         ┃
// ┃ SPDX-License-Identifier: MIT                         ┃
// ┃ <http://www.opensource.org/licenses/MIT>             ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_TYPEALIAS_HPP "1.3.1"

#include <cstddef>
#include <cstdint>
#include <functional>
#include <initializer_list>
#include <memory>
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace argumentative {
inline namespace typealias {
// MARK: Integers
using SizeType = std::size_t;
using UInt = std::uint_fast64_t;
using Int = std::int_fast64_t;
using Char = char;
using Byte = unsigned char;

// MARK: Containers
template <class T>
using InitList = std::initializer_list<T>;
template <class T>
using Vector = std::vector<T>;
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
template <class T>
using Ptr = std::unique_ptr<T>;

static constexpr auto newline = "\r\n";
}  // namespace typealias
}  // namespace argumentative
namespace ive = argumentative;

#endif

namespace argumentative {

class [[maybe_unused]] InvalidOption : public std::exception {
 public:  // MARK: alias
  using Self = InvalidOption;

 protected:  // MARK: member
  static constexpr auto fmt_ = "Option %s wasn't provided with an argument.";
  String msg_;

 public:  // MARK: init
  explicit InvalidOption(StringView opt_name) noexcept : msg_{} {
    const auto len = opt_name.length() + std::strlen(fmt_);
    auto buf = new char[len];
    if (ive::swap_sign(len) <= std::snprintf(buf, len, fmt_, opt_name.data())) {
      msg_ = fmt_;
      msg_ += newline;
      msg_ += __func__;
      msg_ += " ERROR DURING FORMATTING";
    } else {
      msg_ = buf;
    }
    delete[] buf;
  }

 public:  // MARK: instance methods
  [[nodiscard]] char const* what() const noexcept override {
    return msg_.c_str();
  }
};

}  // namespace argumentative
namespace ive = argumentative;
#endif

#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <utility>

namespace argumentative {
enum class ArgKind { version, option, flag, help };

struct Argument {
 public:  // MARK: aliases
  using Self = Argument;

 protected:  // MARK: Polymorphism be damned.
  static constexpr auto kTag = "--";

 public:  // MARK: members
  ArgKind kind;
  String name;
  StringView help;
  String description;

  String value;
  bool seen = false;

 public:  // MARK: init
  Argument(ArgKind kind, StringView name, StringView help) noexcept
      : kind{kind},
        name{String(kTag).append(name)},
        help{help},
        description{this->to_string()},
        value{},
        seen{kind == ArgKind::help or kind == ArgKind::version} {}

  Argument(StringView name, StringView help) noexcept
      : Argument{ArgKind::flag, name, help} {}

  Argument() noexcept = default;
  Argument(Self const&) noexcept = default;
  Argument(Self&&) = default;

  Argument& operator=(Self const&) noexcept = default;

  virtual ~Argument() = default;

 public:  // MARK: instance methods
  [[nodiscard]] String to_string() const {
    auto str = StringStream();
    str << '[' << name;

    switch (kind) {
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

    if (not(this->seen = arg != end)) {
      return false;
    } else if (kind == ArgKind::option) {
      if ((++arg) != end) {
        this->value = *arg;
      } else {
        throw InvalidOption(name);
      }
    }
    return this->seen;
  }

 public:  // MARK: operator overloads
  explicit operator bool() const noexcept { return seen; }

  Argument& operator=(String const& arg) {
    value = arg;
    return *this;
  }

  bool operator==(StringView rhs) const noexcept { return name == rhs; }

  bool operator==(Argument const& rhs) const noexcept {
    return name == rhs.name;
  }

 public:  // MARK: friend operator overloads
  friend std::ostream& operator<<(std::ostream& out,
                                  Self const& self) noexcept {
    const auto len = self.name.length();

    if (len >= 20) {
      out << self.name << '\t';
    } else {
      out << self.name << String(20ull - len, ' ') << '\t';
    }
    return out << self.help;
  }
};

}  // namespace argumentative
namespace ive = argumentative;
#endif

namespace argumentative {

struct Flag : public Argument {
 public:  // MARK: init
  using Argument::Argument;
};

}  // namespace argumentative
namespace ive = argumentative;
#endif

#ifndef VT_HELP_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ Help.hpp:                                            ┃
// ┃ Copyright (c) 2020 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                         ┃
// ┃ SPDX-License-Identifier: MIT                         ┃
// ┃ <http://www.opensource.org/licenses/MIT>             ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_HELP_HPP "1.0.4"

namespace argumentative {

struct Help : public Argument {
  [[maybe_unused]] explicit Help(StringView help) noexcept
      : Argument{ArgKind::help, "help", help} {}

  [[maybe_unused]] Help() noexcept : Help{"Show help for this application."} {}
};

}  // namespace argumentative
namespace ive = argumentative;
#endif

#ifndef VT_VERSION_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ Version.hpp:                                         ┃
// ┃ Copyright (c) 2020 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                         ┃
// ┃ SPDX-License-Identifier: MIT                         ┃
// ┃ <http://www.opensource.org/licenses/MIT>             ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_VERSION_HPP "1.0.1"

namespace argumentative {
struct Version : public Argument {
  [[maybe_unused]] explicit Version(String version) noexcept
      : Argument{ArgKind::version, "version",
                 "Show the version of this application."} {
    this->value = version;
  }
};

}  // namespace argumentative
namespace ive = argumentative;
#endif

#ifndef VT_OPTION_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ Option.hpp:                                          ┃
// ┃ Copyright (c) 2020 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                         ┃
// ┃ SPDX-License-Identifier: MIT                         ┃
// ┃ <http://www.opensource.org/licenses/MIT>             ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_OPTION_HPP "7.2.0"

#include <string_view>
#include <utility>

namespace argumentative {
/**
 * This structure hold a name and the help message.
 * If it is equal to one of the arguments parsed at runtime
 * then an object containing a reference to it and the corresponding argument
 */
struct Option : public Argument {
 public:  // MARK: init
  [[maybe_unused]] Option(StringView name, StringView help) noexcept
      : Argument{ArgKind::option, name, help} {}
};

}  // namespace argumentative
namespace ive = argumentative;
#endif

#endif

#include <algorithm>  // std::copy_if
#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <iterator>  // std::back_inserter
#include <sstream>
#include <string>
#include <string_view>
#include <utility>  // std::move, std::forward
#include <vector>

namespace argumentative {
class Argumentative {
 public:  // MARK: aliases
  using Self = Argumentative;
  using ArgVec = Vector<Argument>;

 private:  // MARK: members
  Vector<StringView> argv_;
  ArgVec args_;
  ArgVec matches_;

  StringView app_name_;
  String app_version_;

 public:  // MARK: init
  [[maybe_unused]] Argumentative(const int argc, char** argv)
      : argv_{argv, argv + argc},
        args_{},
        matches_{},
        app_name_{Self::app_name(argv_[0])},
        app_version_{} {}

  [[maybe_unused]] Argumentative(const int argc, char** argv,
                                 InitList<Argument> args)
      : argv_{argv, argv + argc},
        args_{args.begin(), args.end()},
        matches_{Self::matches(args_, argv_)},
        app_name_{Self::app_name(argv_[0])},
        app_version_{} {}

  // MARK: rule of five
  Argumentative() noexcept = default;
  Argumentative(Self&&) noexcept = default;
  Argumentative(Self const&) noexcept = default;
  Argumentative& operator=(Self const&) noexcept = default;

  virtual ~Argumentative() noexcept = default;

 public:  // MARK: class methods
  static constexpr StringView app_name(StringView prog_path) noexcept {
    return prog_path.substr(prog_path.rfind('/') + 1u);
  }

  static ArgVec matches(ArgVec& args, Vector<StringView> const& argv) noexcept {
    auto matches = ArgVec();
    std::copy_if(std::begin(args), std::end(args),          // Source
                 std::back_inserter(matches),               // Destination
                 [&](auto& arg) { return arg.in(argv); });  // Predicate
    return matches;
  }

 public:  // MARK: instance methods
  Self& append(InitList<Argument> const& args) {
    for (auto const& arg : args) {  // Making a copy.
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

    for (auto const& arg : args_) {
      usage << arg.description << ' ';
    }

    usage << newline;
    for (auto const& arg : args_) {
      usage << newline << arg;
    }

    return usage.str();
  }

  [[nodiscard, maybe_unused]] String version() const noexcept {
    auto version = StringStream();
    version << app_name_ << ' ' << app_version_ << newline;
    return version.str();
  }

 public:  // MARK: operator overloads
  auto operator+=(InitList<Argument> const& args) { return this->append(args); }

  auto operator+=(Argument const& arg) { return this->append(arg); }

  auto operator<<(Argument const& rhs) { return this->append(rhs); }

 public:  // MARK: friend operator overloads
  friend std::ostream& operator<<(std::ostream& out, Self const& self) {
    return out << self.usage();
  }

 public:  // MARK: constraint 'Container'
  [[nodiscard, maybe_unused]] auto empty() const noexcept {
    return matches_.empty();
  }

  [[maybe_unused]] auto begin() noexcept { return matches_.begin(); }

  [[nodiscard, maybe_unused]] auto cbegin() const noexcept {
    return const_cast<ArgVec const&>(matches_).begin();
  }

  [[maybe_unused]] auto rbegin() noexcept { return matches_.rbegin(); }

  [[nodiscard, maybe_unused]] auto crbegin() const noexcept {
    return const_cast<ArgVec const&>(matches_).rbegin();
  }

  [[maybe_unused]] auto end() noexcept { return matches_.end(); }

  [[nodiscard, maybe_unused]] auto cend() const noexcept {
    return const_cast<ArgVec const&>(matches_).end();
  }

  [[maybe_unused]] auto rend() noexcept { return matches_.rend(); }

  [[nodiscard, maybe_unused]] auto crend() const noexcept {
    return const_cast<ArgVec const&>(matches_).rend();
  }
};

}  // namespace argumentative
namespace ive = argumentative;
#endif
