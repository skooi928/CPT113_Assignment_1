#ifndef INVENTORY_H
#define INVENTORY_H
#include "pastry.h"

class Inventory {
private:
    Pastry* pastryList;
    int totalItemNo;
public:
    // Constructor
    Inventory();

    // Destructor
    ~Inventory();
    
    // Get function
    Pastry* getPastryList() const;
    int getItemNumber() const;

    // Read all the stock in the inventory.txt
    // and update it to the pastrylist of Inventory
    void read();

    // Wrire info in pastrylist into inventory.txt
    void write();

    // Check is pastrylist empty
    bool checkAllEmpty() const;

    // Update inventory when item is removed from customer cart
    void addLocalInventory(Pastry);

    // Update pastrylist when new item is added
    bool addPastryList(Pastry&);
    
};

#endif
