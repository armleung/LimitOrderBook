#include "OrderBook.hpp"
#include <iostream>
#include <thread>

OrderBook::OrderBook()
{
}

void OrderBook::placeOrder(OrderPointer order)
{
    auto price = order->getPrice();
    auto side  = order->getSide(); 

    ordersMap[order->getId()] = order;

    if (side == Order::Side::BID) {
        bids.push(price);
        bidsMap[price].push(order);
    } else {
        asks.push(price);
        asksMap[price].push(order);
    }

    doMatching();
}

void OrderBook::doMatching()
{
    while (true) {
        // No Matching happens if either side is empty
        if (bids.empty() || asks.empty()) {
            break;
        }

        auto& askPrice = asks.top();
        auto& bidPrice = bids.top();
        
        // No Matching happens if the best bid is less than the best ask
		if (bidPrice < askPrice){
            break;
        }

        // Matching happens when ask price >= bid price

        // Get the first order in the queue
        auto& askOrder = asksMap[askPrice].front();
        auto& bidOrder = bidsMap[bidPrice].front();

        // Get the volumn of the order
        auto askVolumn = askOrder->getQuantity();
        auto bidVolumn = bidOrder->getQuantity();
        
        // Trade happen
        auto tradePrice = std::min(askPrice, bidPrice);
        auto tradeVolumn = std::min(askVolumn, bidVolumn);
        //std::cout << "Trade happen at price: " << tradePrice  << " volumn: " << tradeVolumn << std::endl;
        
        // Update Order Volumn
        askOrder->setQuantity(askOrder->getQuantity() - tradeVolumn);
        bidOrder->setQuantity(bidOrder->getQuantity() - tradeVolumn);
        
        // Remove the order if the volumn is 0
        if (askOrder->getQuantity() == 0) {
            asksMap[askPrice].pop();
            ordersMap.erase(askOrder->getId());
            asks.pop();
        }
        if (bidOrder->getQuantity() == 0) {
            bidsMap[bidPrice].pop();
            ordersMap.erase(bidOrder->getId());
            bids.pop();
        }
    }
}