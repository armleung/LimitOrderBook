#include <iostream>
#include "OrderBook.hpp"
#include <thread>
#include <chrono>

int main() {
    OrderBook engine;

    // Exact matchs
    std::cout << "Exact matches" << std::endl;
    engine.addOrder(Side::BID, 100, 10);
    engine.addOrder(Side::ASK, 100, 10);

    // Partial match
    std::cout << "Partial match" << std::endl;
    engine.addOrder(Side::BID, 105, 10);
    engine.addOrder(Side::ASK, 105, 5);
    engine.addOrder(Side::ASK, 105, 6);
    engine.addOrder(Side::BID, 105, 1);

    // Price mismatch
    engine.addOrder(Side::BID, 110, 10);
    engine.addOrder(Side::ASK, 105, 10);
    engine.addOrder(Side::ASK, 125, 10);
    return 0;
}