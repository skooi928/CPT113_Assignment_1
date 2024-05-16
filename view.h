#ifndef VIEW_H
#define VIEW_H
#include "inventory.h"
#include "pastry.h"
#include "cart.h"
#include <string>
using namespace std;

class View {
public:
    // Construtor
    View();

    // Destructor
    ~View();

    //User input validation 
    bool validateInput(int, int, int);
    bool validatePieceAndWeight(float, float);
    bool validateOutofStock(int, const Inventory&);
    bool editInfoValidation(string);
    bool editInfoValidation(float);
    bool validateCustomerStateAddress(string); 

    // User sign in 
    int mainmenu();
    int logSignUI();
    void loginUI(string&, string&);
    void signUpUI(string&, string&);
    void failLogin();
    void failSignUP();
    void successLogin(string);
    void successSignUP(string);

    // Staff menu
    int staffMenuDisplay();
    void staffFoodMenuDisplay(const Inventory&);
    int inventoryEditDisplay(Inventory&, int);
    int readItemIdx(Inventory&);
    void addNewItem(Pastry&, const Inventory&);
    void addStatusDisplay(bool);

    // Customer menu
    int customerMenuDisplay();
    int customerFoodMenuDisplay(const Inventory&);
    int customerFoodBuyMethod();
    string customerStateAddress(); 
    float customerBuyByPiece(Pastry&);
    float customerBuyByWeight(Pastry&);
    int displayCart(const Cart&);
    int deleteCartItem(const Cart&);
    void checkPromo();
    int payment(const Cart&, int, float);
    void successPaid(string);

    // Confirm to exit
    bool exitConfirmation();

};

#endif