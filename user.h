#ifndef USER_H
#define USER_H
#include <string>
#include "service.h"
#include "pastry.h"
#include "rating.h"
#include "receipt.h"
#include "view.h"
using namespace std;

class User{
    private:
        string username;
        string password;
        string role;
        // Service service;
        View UI;
    public:
        // Default constructor
        User();
        // Main Menu UI
        void mainmenu(int&);
        // Login/Signup UI
        void logSign(int&);
        // Login function
        void login(int, int&);
        // Sign up function
        void signUP(int);
        void logOut(User*);
};

class Staff : public User{
    public:
        // Default constructor
        Staff();
        // Staff UI

        // Inventory access (Special for staff only)

        // Rating & Feedback access

};

class Customer : public User{
    public:
        // Default constructor
        Customer();
        // Customer UI (menu)

        // Order

        // Rate the food
};

#endif