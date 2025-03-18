# Overview
This project, initiated to demonstrate a basic limit order book in C++, aims to provide a foundational understanding of how orders are managed and executed in financial markets. The limit order book is based on the following key principles:
- Bid: An open offer to buy in the market.
- Ask: An open offer to sell in the market.
- Trade: Occurs when the highest bid price equals the lowest ask price.
- If a trade cannot fill all volumes, the remaining order stays in the order book awaiting the next matching ask or bid.
- Orders are executed at the best possible price first and first come first serve.

# Features
Currently, this limit order book supports:
- Single Stock: Only one stock is supported for simplicity.
- Place Order: Users can place either Ask (sell) or Bid (buy) orders.
- Cancel Order: Users can cancel their placed orders.

# Detailed Design
Data Structures and Performance Considerations
To optimize performance, the following data structures are used:
- Ask Orders: Stored in a minHeap, ensuring the lowest ask price is always at the top. Time complexity for insertion and extraction is O(log n).
- Bid Orders: Stored in a maxHeap, ensuring the highest bid price is always at the top. Time complexity for insertion and extraction is O(log n).
- Order Queue: For orders at the same price, a queue is used to maintain a first-come-first-served (FCFS) order. Time complexity for enqueue and dequeue operations is O(1).
- Volume Calculation: A hashMap is used to store the total volume for each price point. This allows for efficient volume updates without needing to sum all volumes in the queue, reducing the time complexity to O(1) for volume retrieval.
- Cancel Order: Orders are marked with a flag when canceled. During matching, these orders are skipped, and they are removed from the list during search operations.

# Next Steps
Future enhancements could include:
- Notification System: Implement notifications when trades occur at specific price points.
- Market Orders: Support for market orders, which are executed immediately at the best available price.
- Multi-Stock Support: Expand the system to handle multiple stocks.
- Advanced Order Types: Introduce more sophisticated order types, such as stop-loss or limit-stop orders.

# Reference
[Design A Limit Order Book](https://www.youtube.com/watch?v=nmYx6tQxtSs&t=23s)