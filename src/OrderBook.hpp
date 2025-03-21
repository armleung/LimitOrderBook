#ifndef ORDER_BOOK_HPP
#define ORDER_BOOK_HPP  

#include <queue>
#include <unordered_map>

#include "Order.hpp"

using OrderPointer = std::shared_ptr<Order>;
using OrderPointerQueue = std::queue<OrderPointer>;

class OrderBook {
public:
    OrderBook();
    ~OrderBook(){}

    // Simple Order book can do Place order / Cancel order
    void placeOrder(OrderPointer order);

private:
    void doMatching();

    std::priority_queue<Price, std::vector<Price>, std::less<Price>>    bids; // Max heap
    std::priority_queue<Price, std::vector<Price>, std::greater<Price>> asks; // Min heap
    
    std::unordered_map<OrderId, OrderPointer> ordersMap;
    
    // Order Queues 
    std::unordered_map<Price, OrderPointerQueue> bidsMap;
    std::unordered_map<Price, OrderPointerQueue> asksMap;

    // Volumn Maps 
    std::unordered_map<Price, Volumn> bidsVolumn;
    std::unordered_map<Price, Volumn> asksVolumn;
};

#endif // ORDER_BOOK_HPP