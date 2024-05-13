#ifndef PASTRY_H
#define PASTRY_H
#include "rating.h"

// Forward declaration
class Rating;

class Pastry{
    private:
        string itemName;                  // Type of cookies and cakes
        float pricePiece, priceweight;    // Pricing on per-piece basis or fixed weight
        int amount;                       // Number of stocks left
        Rating rate;                      // Feedback comment and score from customer

    public:
        Pastry();                                   //Default Constructor
        Pastry(string,float,float,int);       //Constructor overload
        
        string getName();
        float getPricePiece();
        float getPriceWeight();
        int getAmount();
        



};

#endif