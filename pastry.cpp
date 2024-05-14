#include "pastry.h"
#include <iostream>
using namespace std;

Pastry::Pastry() {}

void storeInfo(fstream& inventoryList, Pastry* pastryList, int totalItemNo) {
    string header;
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

void Pastry::setPastryValue(string t, string f, float wpp, float ppw, float p, float w) {
    type = t;
    flavour = f;
    weightperpiece = wpp;
    priceperweight = ppw;
    piece = p;
    weight = w;
}

Pastry& Pastry :: operator-=(const Pastry& changes) {
    piece -= changes.piece;
    weight -= changes.weight;
    if (piece == 0.0 || weight == 0.0) {
        weight = 0.0;
        piece = 0.0;
    }
    return *this;
}

Pastry& Pastry :: operator+=(const Pastry& changes) {
    piece += changes.piece;
    weight += changes.weight;
    if (piece == 0.0 || weight == 0.0) {
        weight = 0.0;
        piece = 0.0;
    }
    return *this;
}

bool Pastry :: operator==(const Pastry& other) {
    return (type == other.type && flavour == other.flavour);
}


Pastry::Pastry(string type, string flavour, float weightperpiece, float priceperweight, float piece, float weight) {
    type = type;
    flavour = flavour;
    weightperpiece = weightperpiece;
    priceperweight = priceperweight;
    piece = piece;
    weight = weight;
}