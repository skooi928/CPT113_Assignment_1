#ifndef CART_H
#define CART_H
#include "pastry.h"
#include "inventory.h"

class Cart {
private:
    Pastry* inCartItem;
    int amount;
public:
    Cart();
    ~Cart();
    // Add cart
    void addToCart(Pastry);
    int getAmount() const { return amount; };
    Pastry* getInCartItem() const;
    float getTotalPrice(int, bool&) const;
    void deleteFromCart(int);
    void clearCart();
};

#endif
