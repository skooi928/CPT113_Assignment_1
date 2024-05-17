#include "Inventory.h"
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

// The getPastryList method returns a pointer to the array of Pastry objects representing the inventory
Pastry* Inventory::getPastryList() const {
    return pastryList;
}

// The getItemNumber method returns the number of items in the pastry
int Inventory::getItemNumber() const {
    return totalItemNo;
}

// A boolean method to determine whether the inventory is empty
bool Inventory::checkAllEmpty() const {
    for (int i = 0; i < totalItemNo; i++) {
        if (pastryList[i].getPiece() > 0) {
            return false;
        }
    }
    return true;
}

// The addLocalInventory method updates the quantity of a specific pastry item in the inventory
void Inventory::addLocalInventory(Pastry pastryToChange) {
    for (int i = 0; i < totalItemNo; i++) {
        if (pastryList[i] == pastryToChange) {
            // If the pastry item is found in the inventory, increment its quantity
            // Using the overloaded operator
            pastryList[i] += pastryToChange;
            return;
        }
    }
}


// First update to write the inventory by reading the data from inventory.txt
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
