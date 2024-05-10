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
        Service service;
    public:
        // Constructor
        User(string , string , string);
        // Login function
        void login(bool&);
        // Sign up function
        void signUP(int);
};

class Staff : public User{
    public:
        // Constructor
        Staff(string, string);
        // Staff UI

        // Inventory access (Special for staff only)

        // Rating & Feedback access

};

class Customer : public User{
    private:
        Pastry cookie, cake;
        Rating rate;
    public:
        // Constructor
        Customer(string, string);
        // Customer UI (menu)

        // Order

        // Rate the food
};

#endif