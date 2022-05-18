/* Copyright (c) 2017-2022, Hans Erik Thrane */

#include "roq/api.hpp"

#include "roq/samples/event-log/application.hpp"

using namespace std::literals;

namespace {
auto const DESCRIPTION = "Event-Log (Roq Samples)"sv;
}  // namespace

int main(int argc, char **argv) {
  return roq::samples::event_log::Application(
             argc,
             argv,
             {
                 .description = DESCRIPTION,
                 .package_name = ROQ_PACKAGE_NAME,
                 .build_version = ROQ_VERSION,
             })
      .run();
}
