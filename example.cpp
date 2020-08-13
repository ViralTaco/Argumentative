#include "include/Argumentative.hpp"

namespace viraltaco_ {
static void pcount(const int from, const int to) noexcept {
  std::cout << from;
  for (auto i = from + 1; i <= to; ++i) {
    std::cout << ", " << i;
  }
}

static void pcount(const int to) noexcept { pcount(0, to); }
} namespace vt = viraltaco_;

int main(int argc, char** argv) {
  using namespace argumentative;
  Help help; // default help message.
  Version version(VT_ARGUMENTATIVE_HPP);
  Flag line("line", "Print a line after app runs.");
  Option count("count", "Counts up to N.");
  
  Argumentative app(argc, argv);
  app.append(help)
     .append(version)
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
    } else if (arg == version) {
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

