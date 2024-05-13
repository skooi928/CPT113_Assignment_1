#ifndef VIEW_H
#define VIEW_H
#include "inventory.h"
#include "pastry.h"
#include "cart.h"
#include <string>
using namespace std;

class View{
    public:
        void displayPastryMenu();
        void checkPromo();
        void payment();
        void confirmPayment();
        void editMenu();
        void editPromo();
        void checkSales();
 
    
        // All UI here (including logic reasoning)
        bool validateInput(int, int , int);
        bool validatePieceAndWeight(float, float);
        bool validateOutofStock(int, const Inventory &);
        int mainmenu();
        int logSignUI();
        void loginUI(string&, string&);
        void signUpUI(string&, string&);
        void failLogin();
        void failSignUP();
        void successLogin(string);
        void successSignUP(string);
        int staffMenuDisplay();    
        int customerMenuDisplay();
        int customerFoodMenuDisplay(const Inventory &);
        int customerFoodBuyMethod();
        float customerBuyByPiece(Pastry&);
        float customerBuyByWeight(Pastry&);
        int displayCart(const Cart&);
        int deleteCartItem(const Cart&);
        int customerPaymentPage();
};

#endif