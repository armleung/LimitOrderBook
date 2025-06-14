#include "GenerateOrders.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <random>

GenerateOrders::GenerateOrders(OrderBook& _book) : book(_book), gen(rd()) {}

void GenerateOrders::addLimit()
{
    std::uniform_int_distribution<> sharesDist(1, 1000);
    std::normal_distribution<> limitPriceDist(300, 50);
    std::uniform_int_distribution<> buyOrSellDist(0, 1);

    int shares = sharesDist(gen);
    bool buyOrSell = buyOrSellDist(gen);
    int limitPrice;

    if (buyOrSell)
    {
        //do {
            limitPrice = limitPriceDist(gen);
        //} while (limitPrice >= book.getLowestSell());  
    } else {
        //do {
            limitPrice = limitPriceDist(gen);
        //} while (limitPrice <= book.getHighestBuy());  
    }
    file << "AddLimit " << orderId << " " << buyOrSell << " " << shares << " " << limitPrice << std::endl;
    orderId ++;
}

// void GenerateOrders::market()
// {
//     std::uniform_int_distribution<> sharesDist(1, 1000);
//     std::uniform_int_distribution<> buyOrSellDist(0, 1);

//     int shares = sharesDist(gen);
//     bool buyOrSell = buyOrSellDist(gen);

//     file << "Market " << orderId << " " << buyOrSell << " " << shares << std::endl;
//     book->marketOrder(orderId, buyOrSell, shares);
//     orderId ++;
// }

// void GenerateOrders::cancelLimit()
// {
//     Order* order = book->getRandomOrder(0, gen);

//     if (order == nullptr)
//     {
//         addLimit();
//         return;
//     }
//     int orderId = order->getOrderId();
//     file << "CancelLimit " << orderId << std::endl;
//     book->cancelLimitOrder(orderId);
// }

// void GenerateOrders::modifyLimit()
// {
//     std::uniform_int_distribution<> sharesDist(1, 1000);
//     std::normal_distribution<> limitPriceDist(book->getHighestBuy()->getLimitPrice(), 50);

//     int shares = sharesDist(gen);

//     Order* order = book->getRandomOrder(0, gen);

//     if (order == nullptr)
//     {
//         addLimit();
//         return;
//     }
//     int orderId = order->getOrderId();
//     bool buyOrSell = order->getBuyOrSell();
//     int limitPrice;
//     if (buyOrSell)
//     {
//         do {
//             limitPrice = limitPriceDist(gen);
//         } while (limitPrice >= book->getLowestSell()->getLimitPrice());  
//     } else {
//         do {
//             limitPrice = limitPriceDist(gen);
//         } while (limitPrice <= book->getHighestBuy()->getLimitPrice());  
//     }
//     file << "ModifyLimit " << orderId << " " << shares << " " << limitPrice << std::endl;
//     book->modifyLimitOrder(orderId, shares, limitPrice);
// }

// void GenerateOrders::addLimitMarket()
// {
//     std::uniform_int_distribution<> sharesDist(1, 1000);
//     std::uniform_int_distribution<> buyOrSellDist(0, 1);
//     std::normal_distribution<> limitPriceDist(book->getHighestBuy()->getLimitPrice(), 50);

//     int shares = sharesDist(gen);
//     int limitPrice;
//     bool buyOrSell = buyOrSellDist(gen);

//     if (buyOrSell)
//     {
//         limitPrice = book->getLowestSell()->getLimitPrice() + 1;
//     } else {
//         limitPrice = book->getHighestBuy()->getLimitPrice() - 1;
//     }
    
//     file << "AddMarketLimit " << orderId << " " << buyOrSell << " " << shares << " " << limitPrice << std::endl;
//     book->addLimitOrder(orderId, buyOrSell, shares, limitPrice);
//     orderId ++;
// }

// void GenerateOrders::addStop()
// {
//     std::uniform_int_distribution<> sharesDist(1, 1000);
//     std::normal_distribution<> stopPriceDist(book->getHighestBuy()->getLimitPrice(), 50);
//     std::uniform_int_distribution<> buyOrSellDist(0, 1);


//     int shares = sharesDist(gen);
//     bool buyOrSell = buyOrSellDist(gen);

//     int stopPrice;
//     if (buyOrSell)
//     {
//         do {
//             stopPrice = stopPriceDist(gen);
//         } while (stopPrice <= book->getLowestSell()->getLimitPrice());  
//     } else {
//         do {
//             stopPrice = stopPriceDist(gen);
//         } while (stopPrice >= book->getHighestBuy()->getLimitPrice());  
//     }

//     file << "AddStop " << orderId << " " << buyOrSell << " " << shares << " " << stopPrice << std::endl;
//     book->addStopOrder(orderId, buyOrSell, shares, stopPrice);
//     orderId ++;
// }

// void GenerateOrders::cancelStop()
// {
//     Order* order = book->getRandomOrder(1, gen);

//     if (order == nullptr)
//     {
//         addStop();
//         return;
//     }
//     int orderId = order->getOrderId();
//     file << "CancelStop " << orderId << std::endl;
//     book->cancelStopOrder(orderId);
// }

// void GenerateOrders::modifyStop()
// {
//     std::uniform_int_distribution<> sharesDist(1, 1000);
//     std::normal_distribution<> stopPriceDist(book->getHighestBuy()->getLimitPrice(), 50);

//     int shares = sharesDist(gen);

//     Order* order = book->getRandomOrder(1, gen);

//     if (order == nullptr)
//     {
//         addStop();
//         return;
//     }
//     int orderId = order->getOrderId();
//     bool buyOrSell = order->getBuyOrSell();
//     int stopPrice;
//     if (buyOrSell)
//     {
//         do {
//             stopPrice = stopPriceDist(gen);
//         } while (stopPrice <= book->getLowestSell()->getLimitPrice());  
//     } else {
//         do {
//             stopPrice = stopPriceDist(gen);
//         } while (stopPrice >= book->getHighestBuy()->getLimitPrice());  
//     }
//     file << "ModifyStop " << orderId << " " << shares << " " << stopPrice << std::endl;
//     book->modifyStopOrder(orderId, shares, stopPrice);
// }

// void GenerateOrders::addStopLimit()
// {
//     std::uniform_int_distribution<> sharesDist(1, 1000);
//     std::normal_distribution<> stopPriceDist(book->getHighestBuy()->getLimitPrice(), 50);
//     std::uniform_int_distribution<> limitPriceDist(1, 5);
//     std::uniform_int_distribution<> buyOrSellDist(0, 1);


//     int shares = sharesDist(gen);
//     bool buyOrSell = buyOrSellDist(gen);

//     int stopPrice;
//     int limitPrice;
//     if (buyOrSell)
//     {
//         do {
//             stopPrice = stopPriceDist(gen);
//         } while (stopPrice <= book->getLowestSell()->getLimitPrice());  
//         limitPrice = stopPrice + limitPriceDist(gen);
//     } else {
//         do {
//             stopPrice = stopPriceDist(gen);
//         } while (stopPrice >= book->getHighestBuy()->getLimitPrice());
//         limitPrice = stopPrice - limitPriceDist(gen);
//     }

//     file << "AddStopLimit " << orderId << " " << buyOrSell << " " << shares << " " << limitPrice << " " << stopPrice << std::endl;
//     book->addStopLimitOrder(orderId, buyOrSell, shares, limitPrice, stopPrice);
//     orderId ++;
// }

// void GenerateOrders::cancelStopLimit()
// {
//     Order* order = book->getRandomOrder(2, gen);

//     if (order == nullptr)
//     {
//         addStopLimit();
//         return;
//     }
//     int orderId = order->getOrderId();
//     file << "CancelStopLimit " << orderId << std::endl;
//     book->cancelStopLimitOrder(orderId);
// }

// void GenerateOrders::modifyStopLimit()
// {
//     std::uniform_int_distribution<> sharesDist(1, 1000);
//     std::normal_distribution<> stopPriceDist(book->getHighestBuy()->getLimitPrice(), 50);
//     std::uniform_int_distribution<> limitPriceDist(1, 5);

//     int shares = sharesDist(gen);

//     Order* order = book->getRandomOrder(2, gen);

//     if (order == nullptr)
//     {
//         addStopLimit();
//         return;
//     }
//     int orderId = order->getOrderId();
//     bool buyOrSell = order->getBuyOrSell();
//     int stopPrice;
//     int limitPrice;
//     if (buyOrSell)
//     {
//         do {
//             stopPrice = stopPriceDist(gen);
//         } while (stopPrice <= book->getLowestSell()->getLimitPrice());  
//         limitPrice = stopPrice + limitPriceDist(gen);
//     } else {
//         do {
//             stopPrice = stopPriceDist(gen);
//         } while (stopPrice >= book->getHighestBuy()->getLimitPrice());  
//         limitPrice = stopPrice - limitPriceDist(gen);
//     }
//     file << "ModifyStopLimit " << orderId << " " << shares << " " << limitPrice << " " << stopPrice << std::endl;
//     book->modifyStopLimitOrder(orderId, shares, limitPrice, stopPrice);
// }

void GenerateOrders::createOrders(int numberOfOrders)
{
    // Open a file named "orders.txt" for writing
    file.open("orders.txt");

    if (!file.is_open()) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
    }

    for (size_t i = 1; i < numberOfOrders + 1; i++) {
        addLimit();
    }
    file.close();
}

// void GenerateOrders::createInitialOrders(int numberOfOrders, int centreOfBook)
// {
//     // Open a file named "initialOrders.txt" for writing
//     std::ofstream file("C:/Users/benja/Documents/Limit_order_book/initialOrders.txt");

//     if (!file.is_open()) {
//         std::cerr << "Error opening file for writing!" << std::endl;
//         return;
//     }

//     // Define the range for shares and limitPrice
//     std::uniform_int_distribution<> sharesDist(1, 1000);

//     // Define the normal distribution for limitPrice (Mean, SD)
//     std::normal_distribution<> limitPriceDist(centreOfBook, 50);

//     // Adding initial limit orders
//     for (int order = 1; order <= numberOfOrders; ++order) {
//         int shares = sharesDist(gen);
//         int limitPrice = limitPriceDist(gen);
//         bool buyOrSell = limitPrice < centreOfBook;

//         // Writing order to the file
//         file << "AddLimit " << order << " " << buyOrSell << " " << shares << " " << limitPrice << std::endl;
//     }

//     std::uniform_int_distribution<> stopLimitPriceDist(1, 5);
//     std::uniform_int_distribution<> stopOrStopLimitDist(0, 1);

//     // Adding initial stop and stop limit orders
//     for (int order = numberOfOrders + 1; order <= numberOfOrders * 1.1; ++order) {
//         int shares = sharesDist(gen);
//         int stopPrice = limitPriceDist(gen);
//         bool buyOrSell = stopPrice > centreOfBook;
//         bool stopOrStopLimit = stopOrStopLimitDist(gen);

//         if (stopOrStopLimit)
//         {
//             file << "AddStop " << order << " " << buyOrSell << " " << shares << " " << stopPrice << std::endl;
//         } else {
//             int limitPrice;
//             if (buyOrSell)
//             {
//                 limitPrice = stopPrice + stopLimitPriceDist(gen);
//             } else {
//                 limitPrice = stopPrice - stopLimitPriceDist(gen);
//             }
//             file << "AddStopLimit " << order << " " << buyOrSell << " " << shares << " " << limitPrice << " " << stopPrice << std::endl;
//         }
        
//     }


//     // Close the file
//     file.close();

//     std::cout << "Orders written to initialOrders.txt successfully!" << std::endl;
// }