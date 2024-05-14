#ifndef INVENTORY_H
#define INVENTORY_H
#include "pastry.h"

class Inventory{
    private:
        Pastry* pastryList;
        int totalItemNo;
    public:
        // Constructor
        Inventory();
        //Destructor
        ~Inventory();
        // Read all the stock in the inventory.txt
        // and update it to the pastrylist of Inventory
        void read();
        Pastry* getPastryList() const;
        int getItemNumber() const;
        void write();
        bool checkAllEmpty() const;
        void addLocalInventory(Pastry);
        bool expandPastryList(Pastry&);
        void setItemNumber(int);
};

#endif