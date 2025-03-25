#include "gtest/gtest.h"
#include "../src/OrderBook.hpp"
#include "OrderPipeline.hpp"

TEST(OrderBookUnitTest, ExactMatch) {
  OrderBook orderBook;
  orderBook.placeOrder(std::make_shared<Order>(1, Order::Side::BID, 100, 10));
  orderBook.placeOrder(std::make_shared<Order>(2, Order::Side::ASK, 100, 10));
  EXPECT_EQ(orderBook.getOrdersCount(), 0);
}

TEST(OrderBookUnitTest, OneBidFillByMultipleAsk) {
  OrderBook orderBook;
  orderBook.placeOrder(std::make_shared<Order>(3, Order::Side::BID, 100, 10));
  orderBook.placeOrder(std::make_shared<Order>(4, Order::Side::ASK, 100, 5));
  orderBook.placeOrder(std::make_shared<Order>(5, Order::Side::ASK, 100, 5));
  // Trade happen at price: 100 volumn: 10
  EXPECT_EQ(orderBook.getOrdersCount(), 0);
}

TEST(OrderBookUnitTest, OneBidFillByMultipleAskDifferentPrice) {
  OrderBook orderBook;
  orderBook.placeOrder(std::make_shared<Order>(15, Order::Side::ASK, 200, 900));
  orderBook.placeOrder(std::make_shared<Order>(17, Order::Side::ASK, 100, 200));

  orderBook.placeOrder(std::make_shared<Order>(14, Order::Side::BID, 300, 300));
  // Trade happen at price: 100 volumn: 200
  // Trade happen at price: 200 volumn: 100
}

TEST(OrderBookUnitTest, OneAskFillByMultipleBid) {
  OrderBook orderBook;
  orderBook.placeOrder(std::make_shared<Order>(6, Order::Side::BID, 100, 5));
  orderBook.placeOrder(std::make_shared<Order>(7, Order::Side::BID, 100, 5));
  orderBook.placeOrder(std::make_shared<Order>(8, Order::Side::ASK, 100, 10));
  // Trade happen at price: 100 volumn: 10
  EXPECT_EQ(orderBook.getOrdersCount(), 0);
}

TEST(OrderBookUnitTest, PriceMismatch) {
  OrderBook orderBook;
  orderBook.placeOrder(std::make_shared<Order>(9, Order::Side::BID, 110, 10));
  orderBook.placeOrder(std::make_shared<Order>(10, Order::Side::ASK, 105, 10));
  orderBook.placeOrder(std::make_shared<Order>(11, Order::Side::ASK, 125, 10));
  // Trade happen at price: 105 volumn: 10
  EXPECT_EQ(orderBook.getOrdersCount(), 1);
}