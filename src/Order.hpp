#ifndef ORDER_HPP
#define ORDER_HPP

using Price = int;
using Volumn = int;
using OrderId = int;

class Order {
    public:
        enum class Side { BID, ASK };
        Order(int id, Side side, double price, int volumn)
            : id(id), side(side), price(price), volumn(volumn) {}
    
        int getId() const { return id; }
        Side getSide() const { return side; }
        double getPrice() const { return price; }
        int getQuantity() const { return volumn; }
    
        void setQuantity(int newQuantity) { volumn = newQuantity; }
    
    private:
        int id;
        Side side;
        Price price;
        Volumn volumn;
};

#endif // ORDER_HPP