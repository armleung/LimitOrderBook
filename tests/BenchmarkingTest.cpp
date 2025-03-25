#include "gtest/gtest.h"
#include "../src/OrderBook.hpp"
#include "OrderPipeline.hpp"
#include "GenerateOrders.hpp"

TEST(BenchmarkTest, SimpleOneMillionMatchedOrders) {
    OrderBook orderBook;

    for (auto i = 0 ; i < 1000000; i++) {
        orderBook.placeOrder(std::make_shared<Order>(i, Order::Side::BID, 100, 10));
        orderBook.placeOrder(std::make_shared<Order>(i + 1, Order::Side::ASK, 100, 10));
    }
}

TEST(BenchmarkTest, GenerateOrders) {
    OrderBook orderBook;
    GenerateOrders generateOrders(orderBook);
    generateOrders.createOrders(5000000);
}

TEST(BenchmarkTest, OrdersPipeline) {
    OrderBook orderBook;
    OrderPipeline orderPipeline(orderBook);
    orderPipeline.processOrdersFromFile("initialOrders.txt");
    EXPECT_EQ(orderBook.getOrdersCount(), 10000); // Initial 10000 orders without matching
    orderPipeline.processOrdersFromFile("orders.txt");
}