#include "OrderBook.hpp"
#include <iostream>
#include <thread>

OrderBook::OrderBook()
{
}

void OrderBook::addOrder(Side side, Price price, Quantity quantity)
{
    if (side == Side::BID) {
        bids[price] += quantity;
        std::cout << "Bid: " << quantity << " @ " << price << std::endl;
    }
    else {
        asks[price] += quantity;
        std::cout << "Ask: " << quantity << " @ " << price << std::endl;
    }
    doMatching();
}

void OrderBook::cancelOrder(Side side, Price price, Quantity quantity)
{
    if (side == Side::BID) {
        auto it = bids.find(price);
        if (it != bids.end()) {
            it->second -= quantity;
            if (it->second == 0) {
                bids.erase(it);
            }
        }
    }
    else{
        auto it = asks.find(price);
        if (it != asks.end()) {
            it->second -= quantity;
            if (it->second == 0) {
                asks.erase(it);
            }
        }
    }
}

void OrderBook::doMatching()
{
    while (true) {
        // No Matching happens if either side is empty
        if (bids.empty() || asks.empty()) {
            break;
        }

        auto& [askPrice, askQuantity] = *asks.begin();
        auto& [bidPrice, bidQuantity] = *bids.begin();
        
        // No Matching happens if the best bid is less than the best ask
		if (bidPrice < askPrice){
            break;
        }

        // Matching happens
        auto tradeQuantity = std::min(askQuantity, bidQuantity);
        askQuantity -= tradeQuantity;
        bidQuantity -= tradeQuantity;
        std::cout << "Trade: " << tradeQuantity << " @ " << askPrice << std::endl;

        // Remove the order if the quantity is 0
        if (askQuantity == 0) {
            asks.erase(askPrice);
        }
        if (bidQuantity == 0) {
            bids.erase(bidPrice);
        }
    }
}