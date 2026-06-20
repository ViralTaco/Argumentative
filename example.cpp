#include "include/Argumentative.hpp"
#include <iostream>

namespace viraltaco_::inline v3_0_0 {
static auto pcount(const int from, const int to) noexcept -> void {
  std::cout << from;
  for (auto i = from + 1; i <= to; ++i) {
    std::cout << ", " << i;
  }
}

static auto pcount(const int to) noexcept -> void { pcount(0, to); }
} // namespace viraltaco_::inline v3_0_0
namespace vt = viraltaco_;

auto main(int argc, char** argv) -> int {
  argumentative::help h; // default help message.
  argumentative::version v(VT_ARGUMENTATIVE_HPP);
  argumentative::flag line("line", "Print a line after app runs.");
  argumentative::option count("count", "Counts up to N.");
  
  ::argumentative::argumentative app(argc, argv);
  app.append(h)
     .append(v)
     .append(line)
     .append(count);
  
  if (app.empty()) {
    std::cout << app.usage();
    std::exit(EXIT_SUCCESS);
  }
  
  bool print_line = false;
  for (auto const& arg: app) {
    if (arg == line) {
      print_line = true;
    } else if (arg == v) {
      std::cout << app.version();
    } else if (arg == count) {
      const auto to = std::stoi(arg.value);
      vt::pcount(to);
    } else {
      std::cout << app.usage();
    }
  }
  
  if (print_line) { std::cout << std::string(60, '_') << std::endl; }
}
