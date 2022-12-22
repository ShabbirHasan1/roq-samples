/* Copyright (c) 2017-2023, Hans Erik Thrane */

#pragma once

#include "roq/api.hpp"
#include "roq/client.hpp"

namespace roq {
namespace samples {
namespace example_8 {

class Strategy final : public client::Handler {
 public:
  explicit Strategy(client::Dispatcher &);

  Strategy(Strategy &&) = default;
  Strategy(Strategy const &) = delete;

 protected:
  void operator()(Event<DownloadBegin> const &) override;
  void operator()(Event<DownloadEnd> const &) override;
  void operator()(Event<ReferenceData> const &) override;
  void operator()(Event<MarketByPriceUpdate> const &) override;
  void operator()(Event<OrderAck> const &) override;

 private:
  client::Dispatcher &dispatcher_;
  std::string const account_;
  std::string const exchange_;
  std::string const symbol_;
  double const quantity_;
  int32_t const tick_offset_;
  bool downloading_ = false;
  uint32_t order_id_ = 0;
  double tick_size_ = NaN;
  std::unique_ptr<cache::MarketByPrice> market_by_price_;
  std::chrono::nanoseconds wait_ = {};
  uint32_t countdown_ = 32;
};

}  // namespace example_8
}  // namespace samples
}  // namespace roq
