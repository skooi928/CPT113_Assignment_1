#include "inventory.h"
#include <iostream>
#include <fstream>
using namespace std;

Inventory::Inventory() {
    pastryList = nullptr;
    read();
}

Inventory :: ~Inventory() {
    delete[] pastryList;
}

void Inventory::read() {
    delete[] pastryList;
    // Read inventory.txt to get the number of items 
    fstream inventoryList("inventory.txt", ios::in);
    string line;
    // Initialize as -1 to ignore the header of inventory.txt and count from 0
    int totalItemNumber = -1;
    // inventoryList will read inventory.txt to store inside line
    while (getline(inventoryList, line)) {
        totalItemNumber++;
    }
    inventoryList.close();
    totalItemNo = totalItemNumber;
    pastryList = new Pastry[totalItemNo];
    // Read inventory.txt to get and store type, flavour, piece...
    inventoryList.open("inventory.txt", ios::in);
    storeInfo(inventoryList, pastryList, totalItemNo);
    inventoryList.close();
}

Pastry* Inventory::getPastryList() const {
    return pastryList;
}

int Inventory::getItemNumber() const {
    return totalItemNo;
}

bool Inventory::checkAllEmpty() const {
    for (int i = 0; i < totalItemNo; i++) {
        if (pastryList[i].getPiece() > 0) {
            return false;
        }
    }
    return true;
}

void Inventory::addLocalInventory(Pastry pastryToChange) {
    for (int i = 0; i < totalItemNo; i++) {
        if (pastryList[i] == pastryToChange) {
            pastryList[i] += pastryToChange;
            return;
        }
    }
}

void Inventory::write() {
    fstream inventoryList("inventory.txt", ios::trunc | ios::out);
    writeInfo(inventoryList, pastryList, totalItemNo);
    inventoryList.close();
}

bool Inventory::addPastryList(Pastry& newPastry) {
    // If items of newPastry has overlap with items of pastryList, return false 
    for (int i = 0; i < totalItemNo; i++) {
        if (pastryList[i] == newPastry) {
            return false;
        }
    }
    totalItemNo++;
    // Create a newList to store items of pastryList and item of newPastry 
    Pastry* newList=new Pastry[totalItemNo];
    for (int i = 0; i < (totalItemNo-1); i++) {
        newList[i] = pastryList[i];
    }
    // Assign the new items inside newList
    newList[totalItemNo-1] = newPastry;
    delete[] pastryList;
    // Assign address of newList into pastryList 
    pastryList = newList;
    return true;
}

