#ifndef USER_H
#define USER_H
#include "cart.h"
#include <string>
using namespace std;

class User {
protected:
    string username;
    string password;
public:
    // Constructor
    User();

    // Destrutor
    ~User();

    // Get function
    string getUsername() { return username; };

    // Login logic
    virtual bool login(string, string) = 0;
    virtual bool signUP(string, string) = 0;
};

// Inherited base class User
class Staff : public User {
public:
    // Constructor
    Staff();
    
    // Log In logic
    bool login(string, string) override;
    bool signUP(string, string) override;
};


// Inherited base class User
class Customer : public User {
private:
    int purchaseCount;
    Cart shopcart;
public:
    // Constructor
    Customer();

    // Destructor
    ~Destructor();

    // Log In logic
    bool login(string, string) override;
    bool signUP(string, string) override;

    // Get function
    Cart& getCart() { return shopcart; };
    int getPurchaseCount() { return purchaseCount; };

    // Write purchase record of customer in text file
    void addPurchaseRecord();
};

#endif
