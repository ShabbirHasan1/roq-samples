/* Copyright (c) 2017-2023, Hans Erik Thrane */

#pragma once

#include <string_view>

namespace roq {
namespace samples {
namespace example_7 {
namespace flags {

struct Flags final {
  static std::string_view label();
  static std::string_view account();
  static std::string_view exchange();
  static std::string_view symbol();
  static bool simulation();
  static bool subscriber();
};

}  // namespace flags
}  // namespace example_7
}  // namespace samples
}  // namespace roq
