#ifndef PASTRY_H
#define PASTRY_H
#include<iostream>
#include "rating.h"
using namespace std;

// Forward declaration
class Rating;

enum PastryType {
    COOKIE,CAKE
};

class Pastry{
    private:
        PastryType type;                  // cookie or cake
        string itemName;                  // Name of cookies and cakes
        float pricePiece, priceweight;    // Pricing on per-piece basis or fixed weight
        int amount;                       // Number of stocks left
        Rating rate;                      // Feedback comment and score from customer

    public:
        Pastry();                                   //Default Constructor
        Pastry(PastryType,string,float,float,int);       //Constructor overload
        
        string getName();
        float getPricePiece();
        float getPriceWeight();
        int getAmount();
        



};

#endif