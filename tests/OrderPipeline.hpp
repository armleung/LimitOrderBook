#pragma once // Include guard

#include "../src/OrderBook.hpp"

class OrderPipeline {
protected:
    OrderBook& orderBook;

    using OrderFunction = void(OrderPipeline::*)(std::istringstream&);
    std::unordered_map<std::string_view, OrderFunction> orderFunctions;

    void addLimit(std::istringstream& iss);
public:
    OrderPipeline(OrderBook& orderBook);
    void processOrdersFromFile(const std::string& filename);
};