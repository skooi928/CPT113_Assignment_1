#include "Pastry.h"
#include <iostream>
using namespace std;

//Pastry Constructor 
Pastry::Pastry() {}

//Pastry Destructor
Pastry :: ~Pastry(){};

//Friend function for storing info of pastry that located in an arrray
void storeInfo(fstream& inventoryList, Pastry* pastryList, int totalItemNo) {
    string header;
    // To ignore the header of inventoryList and store inside header
    getline(inventoryList, header);
    for (int i = 0; i < totalItemNo; i++) {
        inventoryList >> pastryList[i].type
            >> pastryList[i].flavour
            >> pastryList[i].piece
            >> pastryList[i].weight
            >> pastryList[i].weightperpiece
            >> pastryList[i].priceperweight;
    }
}

//Friend function for write and update the txt file used to saved pastry info
void writeInfo(fstream& inventoryList, Pastry* pastryList, int totalItemNo) {
    inventoryList << "Type Flavour Piece Weight WeightPerPiece PricePerWeight" << endl;
    for (int i = 0; i < totalItemNo; i++) {
        inventoryList << pastryList[i].type << " "
            << pastryList[i].flavour << " "
            << pastryList[i].piece << " "
            << pastryList[i].weight << " "
            << pastryList[i].weightperpiece << " "
            << pastryList[i].priceperweight << endl;
    }
}


void Pastry::setType(string t) {
    type = t;
}

void Pastry::setFlavour(string f) {
    flavour = f;
}

void Pastry::setWPP(float wpp) {
    weightperpiece = wpp;
}

void Pastry::setPPW(float ppw) {
    priceperweight = ppw;
}

void Pastry::setPiece(float p) {
    piece = p;
    if (piece == 0.0) {
        weight = 0.0;
    }
    else {
        weight = p * weightperpiece;
    }
}

void Pastry::setWeight(float w) {
    weight = w;
    if (weight == 0.0) {
        piece = 0.0;
    }
    else {
        piece = w / weightperpiece;
    }
}

//Set value of pastry when adding new item
void Pastry::setPastryValue(string t, string f, float wpp, float ppw, float p, float w) {
    type = t;
    flavour = f;
    weightperpiece = wpp;
    priceperweight = ppw;
    piece = p;
    weight = w;
}

//- Operator overloading to decrease weight, piece of pastry for cart and inventory operations
Pastry& Pastry :: operator-=(const Pastry& changes) {
    piece -= changes.piece;
    weight -= changes.weight;
    if (piece == 0.0 || weight == 0.0) {
        weight = 0.0;
        piece = 0.0;
    }
    return *this;
}

//+ Operator overloading to increase weight, piece of pastry for cart and inventory operations
Pastry& Pastry :: operator+=(const Pastry& changes) {
    piece += changes.piece;
    weight += changes.weight;
    if (piece == 0.0 || weight == 0.0) {
        weight = 0.0;
        piece = 0.0;
    }
    return *this;
}

//= Operator overloading to compare type and name of pastry
bool Pastry :: operator==(const Pastry& other) {
    return (type == other.type && flavour == other.flavour);
}


