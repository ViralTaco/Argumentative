#ifndef VT_INVALID_OPTION_HPP
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ InvalidOption.hpp:                                   ┃
// ┃ Copyright (c) 2020 viraltaco_ (viraltaco@gmx.com)    ┃
// ┃ https://github.com/ViralTaco                         ┃
// ┃ SPDX-License-Identifier: MIT                         ┃
// ┃ <http://www.opensource.org/licenses/MIT>             ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_INVALID_OPTION_HPP "1.0.0"

#include "../../utils/typealias.hpp"

namespace argumentative {

class [[maybe_unused]] InvalidOption: public std::exception {
public: // MARK: alias
  using Self = InvalidOption;
  
protected: // MARK: member
  static constexpr auto fmt_ = "Option %s wasn't provided with an argument.";
  String msg_;
  
public: // MARK: init
  explicit InvalidOption(StringView opt_name) noexcept
    : msg_{ }
  {
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
  
public: // MARK: instance methods
  [[nodiscard]] char const* what() const noexcept override {
    return msg_.c_str();
  }
};

}
namespace ive = argumentative;
#endif
