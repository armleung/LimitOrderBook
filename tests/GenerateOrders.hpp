#pragma once

#include <random>
#include <fstream>
#include "../src/OrderBook.hpp"

class GenerateOrders {
private:
    OrderBook& book;
    int orderId = 11001;
    std::ofstream file;

    // Seed for random number generation
    std::random_device rd;
    std::mt19937 gen;

    //void market();
    void addLimit();
    // void cancelLimit();
    // void modifyLimit();
    // void addLimitMarket();
    // void addStop();
    // void cancelStop();
    // void modifyStop();
    // void addStopLimit();
    // void cancelStopLimit();
    // void modifyStopLimit();

public:
    GenerateOrders(OrderBook& book);
    void createOrders(int numberOfOrders);
};