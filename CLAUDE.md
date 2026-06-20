# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build and Test Commands
The project uses CMake and requires a C++23 compatible compiler.

- **Build project:**
  ```bash
  mkdir -p build && cd build
  cmake ..
  make
  ```
- **Run all tests:**
  ```bash
  # From the build directory
  ./tests/ArgumentativeTests
  ```
- **Run a single test:**
  The current test suite is managed via `TestMain.cpp` and `TestCase.hpp`. To run specific tests, modify `TestMain.cpp` or create a temporary test executable.

## Architecture and Structure
Argumentative is a header-only C++23 command line argument parser.

### Core Components
- **`include/Argumentative.hpp`**: The main entry point for the library.
- **`include/argumentative/argument/`**: Contains the core logic for argument handling:
  - `Argument.hpp`: Base classes and logic for arguments.
  - `Option.hpp`: Handling of options that take values.
  - `Flag.hpp`: Handling of boolean flags.
  - `Help.hpp` & `Version.hpp`: Specialized arguments for generating help and version information.
- **`include/argumentative/utils/`**: Small utility functions and type aliases used across the library.
- **`vt_argumentative.hpp`**: A single-header version of the library for easy integration.

### Project Layout
- `include/`: Source headers for the library.
- `tests/`: Unit tests and test framework.
- `example.cpp`: A usage example demonstrating the library's API.
- `make_header.sh`: Script likely used to generate the single-header `vt_argumentative.hpp`.

### Development Workflow
1. Implement changes in the `include/` directory.
2. Add corresponding tests in the `tests/` directory.
3. Build and run `ArgumentativeTests` to verify changes.
4. Update `vt_argumentative.hpp` using `make_header.sh` if the single-header version needs to be synchronized.

  Role: Expert C++ Refactoring Engineer
  Task: Update the codebase to match the "viraltaco_" architectural and formatting style.

  Style Specifications:

  1. Naming Conventions:
  - Classes/Structs: Use lowercase (e.g., class user_session instead of class UserSession).
  - Functions/Methods: Use snake_case (e.g., calculate_total() instead of calculateTotal()).
  - Private Members: Use snake_case_ with a trailing underscore (e.g., data_).
  - Constants: Use kCamelCase (e.g., kMaxBufferSize).
  - Macros: Use VT_UPPER_CASE (e.g., VT_ENABLE_LOGGING).
  - Namespaces: Implement versioned inline namespaces (e.g., namespace project_name::inline v1_0_0).

  2. Declaration & Signature Style:
  - Return Types: Convert all functions to use trailing return types (e.g., auto get_value() -> int instead of int get_value()).
  - Type Aliasing: Define internal types using using at the top of the class (e.g., using size_type = decltype(0zu);).
  - Attributes:
    - Apply [[nodiscard]] to all functions that return a value without modifying state.
    - Apply noexcept to move operations, getters, and performance-critical utility functions.
  - Constants: Use static constexpr for constants and prefer constexpr lambdas for complex static initializations.

  3. Formatting & Hardware Optimization:
  - Indentation: Use exactly 2 spaces.
  - Organization: Use // MARK: [Section Name] to separate logical blocks in files.
  - Modern C++:
    - Use std::string_view for read-only string parameters.
    - Use C++20/23 ranges (std::ranges, std::views) instead of traditional iterator loops where possible.
    - Use alignas for members that should avoid false sharing (align to cache lines).
  - Literals: Use zu and z suffixes for size_t and ssize_t (e.g., 0zu).

  4. Header Structure:
  - Include #pragma once AND a traditional #ifndef guard.
  - Group includes by category (Standard Library, Third Party, Internal) with comments.

  Instruction: Please review the provided files and apply these changes. Ensure that the logic remains identical, but the "skin" of the code is updated to match this specific
  professional, hardware-aware C++ style.
