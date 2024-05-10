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
        // Constructor
        User(string , string , string);
        // Login function
        void login(bool&);
        // Sign up function
        void signUP(int);
};

class Staff : public User{
    public:
        // Default constructor
        Staff();
        // Constructor
        Staff(string, string);
        // Staff UI

        // Inventory access (Special for staff only)

        // Rating & Feedback access

};

class Customer : public User{
    public:
        // Default constructor
        Customer();
        // Constructor
        Customer(string, string);
        // Customer UI (menu)

        // Order

        // Rate the food
};

#endif