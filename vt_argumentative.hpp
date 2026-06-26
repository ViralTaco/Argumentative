#pragma once

// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ Argumentative.hpp:                                        ┃
// ┃ Copyright (c) 2020, 2026 viraltaco_ (viraltaco@gmx.com)   ┃
// ┃ https://github.com/ViralTaco                              ┃
// ┃ SPDX-License-Identifier: MIT                              ┃
// ┃ <http://www.opensource.org/licenses/MIT>                  ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_ARGUMENTATIVE_HPP "3.1.0"

// Standard Library
#include <algorithm>  // std::copy_if
#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <iterator>  // std::back_inserter
#include <ranges>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>  // std::move, std::forward
#include <vector>

// Internal

// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ typealias.hpp:                                            ┃
// ┃ Copyright (c) 2020, 2026 viraltaco_ (viraltaco@gmx.com)   ┃
// ┃ https://github.com/ViralTaco                              ┃
// ┃ SPDX-License-Identifier: MIT                              ┃
// ┃ <http://www.opensource.org/licenses/MIT>                  ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_TYPEALIAS_HPP "3.1.0"

// Standard Library
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

namespace argumentative::inline v3_1_0 {
inline namespace typealias {
// MARK: Integers
using size_type = std::size_t;
using uint_type = std::uint_fast64_t;
using int_type = std::int_fast64_t;
using char_type = char;
using byte_type = unsigned char;

// MARK: Containers
template <class T>
using init_list = std::initializer_list<T>;
template <class T>
using vector = std::vector<T>;
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
template <class T>
using ptr = std::unique_ptr<T>;

static constexpr auto kNewline = "\r\n";
}  // namespace typealias
}  // namespace argumentative::inline v3_1_0

#endif

// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ Argument.hpp:                                              ┃
// ┃ Copyright (c) 2020, 2026 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                               ┃
// ┃ SPDX-License-Identifier: MIT                               ┃
// ┃ <http://www.opensource.org/licenses/MIT>                   ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_ARGUMENT_HPP "3.1.0"

// Standard Library
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <string_view>
#include <utility>

// Internal

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

}  // namespace argumentative::inline v3_1_0

// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ InvalidOption.hpp:                                        ┃
// ┃ Copyright (c) 2020, 2026 viraltaco_ (viraltaco@gmx.com)   ┃
// ┃ https://github.com/ViralTaco                              ┃
// ┃ SPDX-License-Identifier: MIT                              ┃
// ┃ <http://www.opensource.org/licenses/MIT>                  ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_INVALID_OPTION_HPP "3.1.0"

// Standard Library
#include <exception>
#include <sstream>
#include <string>

// Internal

namespace argumentative::inline v3_1_0 {

class [[maybe_unused]] invalid_option : public std::exception {
 protected:  // MARK: member
  static constexpr auto kFmt = [](const auto s) -> string {
    auto fmt = string_stream();
    fmt << "Option " << s << " wasn't provided with an argument.";
    return fmt.str();
  };
  string msg_;

 public:  // MARK: init
  explicit invalid_option(string_view opt_name) noexcept
      : msg_{kFmt(opt_name)} {}

 public:  // MARK: instance methods
  [[nodiscard]] auto what() const noexcept -> char const* override {
    return msg_.c_str();
  }
};

}  // namespace argumentative::inline v3_1_0
#endif

namespace argumentative::inline v3_1_0 {
enum class arg_kind { version, option, flag, help };

struct argument {
 public:  // MARK: aliases
  using self = argument;

 public:  // MARK: constants
  static constexpr auto kTag = "--";

 private:  // MARK: members
  arg_kind kind_;
  string name_;
  string_view help_;
  string description_;

  string value_;
  bool seen_ = false;

 public:  // MARK: getters
  [[nodiscard]] constexpr auto kind() const noexcept -> arg_kind {
    return kind_;
  }
  [[nodiscard]] auto name() const noexcept -> string const& { return name_; }
  [[nodiscard]] constexpr auto help() const noexcept -> string_view {
    return help_;
  }
  [[nodiscard]] auto description() const noexcept -> string const& {
    return description_;
  }
  [[nodiscard]] auto value() const noexcept -> string const& { return value_; }
  [[nodiscard]] constexpr auto seen() const noexcept -> bool { return seen_; }

 public:  // MARK: init
  argument(arg_kind arg_kind, string_view arg_name,
           string_view arg_help) noexcept
      : kind_{arg_kind},
        name_{string(kTag).append(arg_name)},
        help_{arg_help},
        description_{this->to_string()},
        value_{},
        seen_{arg_kind == arg_kind::help or arg_kind == arg_kind::version} {}

  argument(string_view name, string_view help) noexcept
      : argument{arg_kind::flag, name, help} {}

  argument() noexcept = delete;
  argument(self const&) noexcept = default;
  argument(self&&) noexcept = default;

  auto operator=(self const&) noexcept -> argument& = default;

  virtual ~argument() = default;

 public:  // MARK: instance methods
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

    if (not(this->seen_ = arg != end)) {
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

 public:  // MARK: operator overloads
  explicit operator bool() const noexcept { return seen_; }

  auto operator=(string const& arg_str) -> argument& {
    value_ = arg_str;
    return *this;
  }

  [[nodiscard]] auto operator==(string_view rhs) const noexcept -> bool {
    return name_ == rhs;
  }

  [[nodiscard]] auto operator==(argument const& rhs) const noexcept -> bool {
    return name_ == rhs.name_;
  }

 public:  // MARK: friend operator overloads
  friend auto operator<<(std::ostream& out, self const& self) noexcept
      -> std::ostream& {
    const auto padding = 20 - self.name_.length();
    return out << self.name_ << std::setw((padding > 0) ? padding : 1)
               << std::right << '\t' << self.help_;
  }
};

}  // namespace argumentative::inline v3_1_0
#endif

// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ Flag.hpp:                                                 ┃
// ┃ Copyright (c) 2020, 2026 viraltaco_ (viraltaco@gmx.com)   ┃
// ┃ https://github.com/ViralTaco                              ┃
// ┃ SPDX-License-Identifier: MIT                              ┃
// ┃ <http://www.opensource.org/licenses/MIT>                  ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_FLAG_HPP "3.1.0"

// Internal

namespace argumentative::inline v3_1_0 {

struct flag : public argument {
  using argument::argument;
};

}  // namespace argumentative::inline v3_1_0
#endif

// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ Option.hpp:                                               ┃
// ┃ Copyright (c) 2020, 2026 viraltaco_ (viraltaco@gmx.com)   ┃
// ┃ https://github.com/ViralTaco                              ┃
// ┃ SPDX-License-Identifier: MIT                              ┃
// ┃ <http://www.opensource.org/licenses/MIT>                  ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_OPTION_HPP "3.1.0"

// Standard Library
#include <string_view>
#include <utility>

// Internal

namespace argumentative::inline v3_1_0 {
/**
 * This structure hold a name and the help message.
 * If it is equal to one of the arguments parsed at runtime
 * then an object containing a reference to it and the corresponding argument
 */
struct option : public argument {
 public:  // MARK: init
  [[maybe_unused]] option(string_view name, string_view help) noexcept
      : argument{arg_kind::option, name, help} {}
};

}  // namespace argumentative::inline v3_1_0
#endif

// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ Help.hpp:                                                 ┃
// ┃ Copyright (c) 2020, 2026 viraltaco_ (viraltaco@gmx.com)   ┃
// ┃ https://github.com/ViralTaco                              ┃
// ┃ SPDX-License-Identifier: MIT                              ┃
// ┃ <http://www.opensource.org/licenses/MIT>                  ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_HELP_HPP "3.1.0"

// Internal

namespace argumentative::inline v3_1_0 {

struct help : public argument {
  [[maybe_unused]] explicit help(string_view help_str) noexcept
      : argument{arg_kind::help, "help", help_str} {}

  [[maybe_unused]] help() noexcept : help{"Show help for this application."} {}
};

}  // namespace argumentative::inline v3_1_0
#endif

// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ Version.hpp:                                              ┃
// ┃ Copyright (c) 2020, 2026 viraltaco_ (viraltaco@gmx.com)   ┃
// ┃ https://github.com/ViralTaco                              ┃
// ┃ SPDX-License-Identifier: MIT                              ┃
// ┃ <http://www.opensource.org/licenses/MIT>                  ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_VERSION_HPP "3.1.0"

// Standard Library
#include <utility>

// Internal

namespace argumentative::inline v3_1_0 {
struct version : public argument {
  [[maybe_unused]] explicit version(string version_str) noexcept
      : argument{arg_kind::version, "version",
                 "Show the version of this application."} {
    argument::operator=(std::move(version_str));
  }
};

}  // namespace argumentative::inline v3_1_0
#endif

namespace argumentative::inline v3_1_0 {
class argumentative {
 public:  // MARK: aliases
  using self = argumentative;
  using arg_vec = vector<argument>;

 private:  // MARK: members
  alignas(64) vector<string_view> argv_;
  alignas(64) arg_vec args_;
  alignas(64) arg_vec matches_;

  string_view app_name_;
  string app_version_;

 public:  // MARK: init
  [[maybe_unused]] argumentative(const int argc, char** argv)
      : argv_{argv, argv + argc},
        args_{},
        matches_{},
        app_name_{self::app_name(argv_[0])},
        app_version_{} {}

  [[maybe_unused]] argumentative(const int argc, char** argv,
                                 init_list<argument> args)
      : argv_{argv, argv + argc},
        args_{args.begin(), args.end()},
        matches_{self::matches(args_, argv_)},
        app_name_{self::app_name(argv_[0])},
        app_version_{} {}

  // MARK: rule of five
  argumentative() noexcept = default;
  argumentative(self&&) noexcept = default;
  argumentative(self const&) noexcept = default;
  auto operator=(self const&) noexcept -> argumentative& = default;

  virtual ~argumentative() = default;

 public:  // MARK: class methods
  [[nodiscard]] static constexpr auto app_name(string_view prog_path) noexcept
      -> string_view {
    return prog_path.substr(prog_path.rfind('/') + 1zu);
  }

  [[nodiscard]] static auto matches(arg_vec& args,
                                    vector<string_view> const& argv)
      -> arg_vec {
    auto matches = arg_vec();

    for (auto& arg :
         args | std::views::filter([&](auto& a) { return a.in(argv); })) {
      matches.push_back(arg);
    }

    return matches;
  }

 public:  // MARK: instance methods
  auto append(init_list<argument> const& args) -> self& {
    for (auto const& arg : args) {  // Making a copy.
      this->append(arg);
    }
    return *this;
  }

  auto append(argument arg) -> self& {
    args_.push_back(arg);
    if (arg.kind() == arg_kind::version) {
      app_version_ = arg.value();
    }
    if (arg.in(argv_)) {
      matches_.push_back(arg);
    }
    return *this;
  }

  [[nodiscard]] auto usage() const -> string {
    auto usg = string_stream();
    usg << "Usage: " << app_name_ << ' ';

    for (auto const& arg : args_) {
      usg << arg.description() << ' ';
    }

    usg << kNewline;
    for (auto const& arg : args_) {
      usg << kNewline << arg;
    }

    return usg.str();
  }

  [[nodiscard, maybe_unused]] auto version() const -> string {
    auto ver = string_stream();
    ver << app_name_ << ' ' << app_version_ << kNewline;
    return ver.str();
  }

 public:  // MARK: operator overloads
  auto operator+=(init_list<argument> const& args) -> auto {
    return this->append(args);
  }

  auto operator+=(argument const& arg) -> auto { return this->append(arg); }

  auto operator<<(argument const& rhs) -> auto { return this->append(rhs); }

 public:  // MARK: friend operator overloads
  friend auto operator<<(std::ostream& out, self const& self) -> std::ostream& {
    return out << self.usage();
  }

 public:  // MARK: constraint 'Container'
  [[nodiscard, maybe_unused]] auto empty() const noexcept -> bool {
    return matches_.empty();
  }

  [[maybe_unused]] auto begin() noexcept -> auto { return matches_.begin(); }

  [[nodiscard, maybe_unused]] auto cbegin() const noexcept -> auto {
    return const_cast<arg_vec const&>(matches_).begin();
  }

  [[maybe_unused]] auto rbegin() noexcept -> auto { return matches_.rbegin(); }

  [[nodiscard, maybe_unused]] auto crbegin() const noexcept -> auto {
    return const_cast<arg_vec const&>(matches_).rbegin();
  }

  [[maybe_unused]] auto end() noexcept -> auto { return matches_.end(); }

  [[nodiscard, maybe_unused]] auto cend() const noexcept -> auto {
    return const_cast<arg_vec const&>(matches_).end();
  }

  [[maybe_unused]] auto rend() noexcept -> auto { return matches_.rend(); }

  [[nodiscard, maybe_unused]] auto crend() const noexcept -> auto {
    return const_cast<arg_vec const&>(matches_).rend();
  }
};

}  // namespace argumentative::inline v3_1_0
#endif
