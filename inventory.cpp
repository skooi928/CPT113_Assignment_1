#include "inventory.h"
#include <iostream>
#include <fstream>
using namespace std;

Inventory :: Inventory(){
    pastryList = nullptr;
    read();
}

Inventory :: ~Inventory(){
    delete [] pastryList;
}

void Inventory :: read(){
    delete [] pastryList;
    fstream inventoryList("inventory.txt", ios::in);
    string line;
    // Get how many total item in the inventory
    int totalItemNumber = -1;
    while(getline(inventoryList, line)){
        totalItemNumber++;
    }
    inventoryList.close();
    totalItemNo = totalItemNumber;
    // Create a list of pastry
    pastryList = new Pastry [totalItemNo];
    inventoryList.open("inventory.txt", ios::in);
    storeInfo(inventoryList, pastryList, totalItemNo);
    inventoryList.close();
}

Pastry* Inventory :: getPastryList() const{
    return pastryList;
}

int Inventory :: getItemNumber() const{
    return totalItemNo;
}

bool Inventory :: checkAllEmpty() const{
    for(int i = 0; i < totalItemNo; i++){
        if(pastryList[i].getPiece() > 0){
            return false;
        }
    }
    return true;
}

void Inventory :: addLocalInventory(Pastry pastryToChange){
    for(int i = 0; i < totalItemNo; i++){
        if(pastryList[i] == pastryToChange){
            pastryList[i] += pastryToChange;
            return;
        }
    }
}

void Inventory :: write(){
    fstream inventoryList("inventory.txt", ios::trunc | ios::out);
    writeInfo(inventoryList, pastryList, totalItemNo);
    inventoryList.close();
}