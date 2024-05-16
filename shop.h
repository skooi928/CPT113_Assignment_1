#ifndef SHOP_H
#define SHOP_H
#include "user.h"
#include "view.h"
#include "inventory.h"
#include "pastry.h"

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
