#include "OrderPipeline.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <chrono>
#include <map>

OrderPipeline::OrderPipeline(OrderBook &orderBook)
    : orderBook(orderBook)
{
    orderFunctions["AddLimit"] = &OrderPipeline::addLimit;
}

void OrderPipeline::addLimit(std::istringstream &iss)
{
    int orderId, shares, limitPrice;
    bool buyOrSell;
    iss >> orderId >> buyOrSell >> shares >> limitPrice;
    orderBook.placeOrder(std::make_shared<Order>(orderId, static_cast<Order::Side>(buyOrSell), limitPrice, shares));
}

void OrderPipeline::processOrdersFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::ofstream csvFile("order_processing_times.csv", std::ios::trunc); // Open in append mode
    if (!csvFile.is_open()) {
        std::cerr << "Error opening CSV file for writing." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string orderType;
        iss >> orderType;

        auto it = orderFunctions.find(orderType);
            if (it != orderFunctions.end()) {
                auto start = std::chrono::steady_clock::now();

                (this->*(it->second))(iss);

                auto end = std::chrono::steady_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
                
                csvFile << orderType << "," << duration.count() << std::endl;
                
            } else {
                std::cerr << "Unknown order type: " << orderType << std::endl;
            }
    }
    file.close();
    csvFile.close();
}