#include "src/Argumentative.hpp"

namespace viraltaco_ {
static void pcount(const int from, const int to) noexcept {
  std::cout << from;
  for (auto i = from + 1; i <= to; ++i) {
    std::cout << ", " << i;
  }
}

static void pcount(const int to) noexcept { pcount(0, to); }
}

int main(int argc, char** argv) {
  using namespace viraltaco_;
  
  Flag help("help", "Show this help message");
  Flag version("version", "Show the version number");
  Option count("count", "Counts up to N");
  
  Argumentative app(argc, argv);
  app.append(help)
     .append(version)
     .append(count);
  
  if (app.empty()) {
    std::cout << app.usage();
    std::exit(EXIT_SUCCESS);
  }
  
  for (auto const& arg: app) {
    if (arg == version) {
      std::cout << app.version();
    } else if (arg == count) {
      const auto to = std::stoi(arg.value);
      vt::pcount(to);
    } else {
      std::cout << app.usage();
    }
  }
}

