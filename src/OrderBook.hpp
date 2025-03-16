#ifndef ORDER_BOOK_HPP
#define ORDER_BOOK_HPP  

#include <map>

// Temp typedefs for now
using Price = int;
using Quantity = int;

enum class Side {
    BID,
    ASK
};

class OrderBook {
public:
    OrderBook();
    ~OrderBook(){}

    // Simple Order book can do Add order / Cancel order
    void addOrder(Side side, Price price, Quantity quantity);
    void cancelOrder(Side side, Price price, Quantity quantity);

private:
    void doMatching();
    std::map<Price, Quantity, std::less<Price>> asks; 
    std::map<Price, Quantity, std::greater<Price>> bids; 
};

#endif // ORDER_BOOK_HPP