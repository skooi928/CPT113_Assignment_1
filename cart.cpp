#include "cart.h"
#include "pastry.h"
#include "inventory.h"
#include <iostream>
using namespace std;

// Cart constructor
Cart::Cart() {
    inCartItem = nullptr;
    amount = 0;
}

// Cart destructor
Cart :: ~Cart() {
    delete[] inCartItem;
    amount = 0;
}

void Cart::addToCart(Pastry newPastry) {
    // Update the amount if pastry present in the cart
    for (int i = 0; i < amount; i++) {
        if (inCartItem[i] == newPastry) {
            inCartItem[i] += newPastry;
            return;
        }
    }
    // Adding new item into cart 
    amount++;
    Pastry* temp = new Pastry[amount];
    for (int i = 0; i < amount - 1; i++) {
        temp[i] = inCartItem[i];
    }
    temp[amount - 1] = newPastry;
    delete[] inCartItem;
    inCartItem = temp;
}

void Cart::deleteFromCart(int userInput) {

    amount--;
    Pastry* temp = new Pastry[amount];
    for (int i = 0; i < userInput - 1; i++) {
        temp[i] = inCartItem[i];
    }
    for (int i = userInput - 1; i < amount; i++) {
        temp[i] = inCartItem[i + 1];
    }
    delete[] inCartItem;
    inCartItem = temp;
}

Pastry* Cart::getInCartItem() const {
    return inCartItem;
}

float Cart::getTotalPrice(int discount, bool& gotDiscount) const {
    float total=0;
    for (int i = 0; i < amount; i++) {
        total += inCartItem[i].getPrice();
    }
    if (discount % 5 == 0) {
        gotDiscount = true;
        return total * 0.9;
    }
    return total;
}

void Cart::clearCart() {
    delete[] inCartItem;
    inCartItem = nullptr;
    amount = 0;
}