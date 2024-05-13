#ifndef USER_H
#define USER_H
#include "cart.h"
#include <string>
using namespace std;

class User{
    protected:
        string username;
        string password;
    public:
        User();
        string getUsername(){return username;};
        virtual bool login(string, string) = 0;
        virtual bool signUP(string, string) = 0;
};

class Staff : public User{
    public:
        // Constructor
        Staff();
        // Log In logic
        bool login(string, string) override;
        bool signUP(string, string) override;
};

class Customer : public User{
    private:
        int purchaseCount;
        Cart shopcart;
    public:
        // Constructor
        Customer();
        bool login(string, string) override;
        bool signUP(string, string) override;
        Cart& getCart(){return shopcart;};
        void addPurchaseRecord();
        int getPurchaseCount(){return purchaseCount;};
};

#endif