#ifndef CART_H
#define CART_H
#include "pastry.h"
#include "inventory.h"

class Cart {
private:
    Pastry* inCartItem;
    int amount;
public:
    // Constrcutor
    Cart();

    // Destructor
    ~Cart();

    // Get function
    int getAmount() const { return amount; };
    Pastry* getInCartItem() const;
    float getTotalPrice(int, bool&) const;

    // Add pastry into cart
    void addToCart(Pastry);
    
    // Delete pastry into cart
    void deleteFromCart(int);

    // Clear all items in cart
    void clearCart();
};

#endif
