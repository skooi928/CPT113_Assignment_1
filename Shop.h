#ifndef SHOP_H
#define SHOP_H
#include "User.h"
#include "View.h"
#include "Inventory.h"
#include "Pastry.h"

class Shop {
private:
    User* user;
    View UI;
    Inventory inventory;
public:
    // Shop constructor
    Shop();
    // Shop destructor
    ~Shop();
    // Start
    void main();
    // Staff Login/Signup
    int staffLogSign();
    // Customer Login/Signup
    int customerLogSign();
    // Staff Menu
    int staffMenu();
    // Customer Menu
    int customerMenu();
    // Customer Payment Menu
    int customerPayment();
};

#endif
