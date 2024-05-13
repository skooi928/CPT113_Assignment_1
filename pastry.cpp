#include "pastry.h"
#include <iostream>
using namespace std;

Pastry :: Pastry(){}

void storeInfo(fstream &inventoryList, Pastry* pastryList, int totalItemNo){
    string header;
    getline(inventoryList,header);
    for(int i = 0; i < totalItemNo; i++){
        inventoryList >> pastryList[i].type 
                      >> pastryList[i].flavour 
                      >> pastryList[i].piece 
                      >> pastryList[i].weight 
                      >> pastryList[i].weightperpiece 
                      >> pastryList[i].priceperweight;
    }
}

void Pastry :: setPiece(float p){
    piece = p;
    weight = p*weightperpiece;
}

void Pastry :: setWeight(float w){
    piece = w/weightperpiece;
    weight = w;
}

Pastry& Pastry :: operator-=(const Pastry& changes){
    piece -= changes.piece;
    weight -= changes.weight;
    return *this;
}

Pastry& Pastry :: operator+=(const Pastry& changes){
    piece += changes.piece;
    weight += changes.weight;
    return *this;
}

bool Pastry :: operator==(const Pastry& other){
    return (type == other.type && flavour == other.flavour);
}