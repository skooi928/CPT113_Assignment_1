#ifndef USER_H
#define USER_H
#include <string>
#include "service.h"
#include "pastry.h"
#include "rating.h"
#include "receipt.h"
using namespace std;

class User{
    private:
        string username;
        string password;
        string role;
    public:
        // Default constructor
        User();
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