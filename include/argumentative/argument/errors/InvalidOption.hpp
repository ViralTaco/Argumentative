#ifndef VT_INVALID_OPTION_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ InvalidOption.hpp:                                   ┃
// ┃ Copyright (c) 2020 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                         ┃
// ┃ SPDX-License-Identifier: MIT                         ┃
// ┃ <http://www.opensource.org/licenses/MIT>             ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_INVALID_OPTION_HPP "2.0.0"

#include <exception> // std::exception
#include <string>    // std::string
#include <sstream>   // std::stringstream

#include "../../utils/typealias.hpp"

namespace argumentative {

class [[maybe_unused]] InvalidOption: public std::exception {
protected: // MARK: member
  static constexpr auto fmt_ = [] (const auto s) {
    auto fmt = StringStream();
    fmt << "Option " << s << " wasn't provided with an argument.";
    return fmt.str();
  };
  String msg_;
  
public: // MARK: init
  explicit InvalidOption(StringView opt_name) noexcept
    : msg_{ fmt_(opt_name) }
  {}
  
public: // MARK: instance methods
  [[nodiscard]] char const* what() const noexcept override {
    return msg_.c_str();
  }
};

}
namespace ive = argumentative;
#endif
