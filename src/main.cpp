#include <iostream>
#include "OrderBook.hpp"
#include "Order.hpp"
#include <thread>
#include <chrono>

int main() {
    OrderBook orderBook;

    // Exact matchs
    std::cout << "Exact matches" << std::endl;
    orderBook.placeOrder(std::make_shared<Order>(1, Order::Side::BID, 100, 10));
    orderBook.placeOrder(std::make_shared<Order>(2, Order::Side::ASK, 100, 10));
    // Trade happen at price: 100 volumn: 10

    // Partial match
    std::cout << "Partial match" << std::endl;
    orderBook.placeOrder(std::make_shared<Order>(3, Order::Side::BID, 100, 10));
    orderBook.placeOrder(std::make_shared<Order>(4, Order::Side::ASK, 100, 5));
    // Trade happen at price: 100 volumn: 5

    orderBook.placeOrder(std::make_shared<Order>(5, Order::Side::BID, 100, 10));
    orderBook.placeOrder(std::make_shared<Order>(6, Order::Side::ASK, 100, 15));
    // Trade happen at price: 100 volumn: 15
    orderBook.placeOrder(std::make_shared<Order>(7, Order::Side::BID, 105, 6));
    orderBook.placeOrder(std::make_shared<Order>(8, Order::Side::ASK, 105, 1));
    // Trade happen at price: 105 volumn: 1

    // Price mismatch
    std::cout << "Price mismatch" << std::endl;
    orderBook.placeOrder(std::make_shared<Order>(9, Order::Side::BID, 110, 10));
    orderBook.placeOrder(std::make_shared<Order>(10, Order::Side::ASK, 105, 10));
    orderBook.placeOrder(std::make_shared<Order>(11, Order::Side::ASK, 125, 10));
    // Trade happen at price: 105 volumn: 10
    return 0;
}