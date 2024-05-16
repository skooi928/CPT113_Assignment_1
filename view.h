#ifndef VIEW_H
#define VIEW_H
#include "inventory.h"
#include "pastry.h"
#include "cart.h"
#include <string>
using namespace std;

class View {
public:
    void displayPastryMenu();
    void checkPromo();
    int payment(const Cart&, int);
    void successPaid(string);

    // All UI here (including logic reasoning)
    bool validateInput(int, int, int);
    bool validatePieceAndWeight(float, float);
    bool validateOutofStock(int, const Inventory&);
    int mainmenu();
    int logSignUI();
    void loginUI(string&, string&);
    void signUpUI(string&, string&);
    void failLogin();
    void failSignUP();
    void successLogin(string);
    void successSignUP(string);
    int staffMenuDisplay();
    void staffFoodMenuDisplay(const Inventory&);
    int inventoryEditDisplay(Inventory&, int);
    int readItemIdx(Inventory&);
    bool editInfoValidation(string);
    bool editInfoValidation(float);
    void addNewItem(Pastry&, const Inventory&);
    void addStatusDisplay(bool);
    int customerMenuDisplay();
    int customerFoodMenuDisplay(const Inventory&);
    int customerFoodBuyMethod(); 
    float customerBuyByPiece(Pastry&);
    float customerBuyByWeight(Pastry&);
    int displayCart(const Cart&);
    int deleteCartItem(const Cart&);
    bool exitConfirmation();

    
    Pastry* addNewItem2(const Inventory& inventory);
};

#endif