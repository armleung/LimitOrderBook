#ifndef ORDER_BOOK_HPP
#define ORDER_BOOK_HPP  

#include <queue>
#include <unordered_map>
#include <memory>
#include "Order.hpp"

using OrderPointer = std::shared_ptr<Order>;
using OrderPointerQueue = std::queue<OrderPointer>;

class OrderBook {
public:
    OrderBook();
    ~OrderBook(){}

    // Simple Order book can do Place order / Cancel order
    void placeOrder(OrderPointer order);

public:
    // Getters
    int getOrdersCount() const { return ordersMap.size(); }
    Price getLowestSell() const { return asks.top(); }
    Price getHighestBuy() const { return bids.top(); }
    
private:
    void doMatching();

    std::priority_queue<Price, std::vector<Price>, std::less<Price>>    bids; // Max heap
    std::priority_queue<Price, std::vector<Price>, std::greater<Price>> asks; // Min heap
    
    std::unordered_map<OrderId, OrderPointer> ordersMap;
    
    // Order Queues 
    std::unordered_map<Price, OrderPointerQueue> bidsMap;
    std::unordered_map<Price, OrderPointerQueue> asksMap;
};

#endif // ORDER_BOOK_HPP