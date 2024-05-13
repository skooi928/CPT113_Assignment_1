#include "shop.h"
#include "user.h"
#include "inventory.h"
#include "pastry.h"
#include "cart.h"
#include "view.h"
#include <iostream>
using namespace std;

Shop :: Shop(){
    user = nullptr;
}

Shop :: ~Shop(){
    delete user;
}

void Shop :: start(){
    delete user;
    user = nullptr;
    while(true){
        int choice, returnChoice;
        choice = UI.mainmenu();
        switch (choice){
            case 0:
                cout<<"\nThanks for your visiting!"<<endl;
                return; // To exit the function
            case 1:
                // Call staff menu
                returnChoice = staffLogSign();
                if(returnChoice == 0){
                    cout<<"\nProgram Ended. Keep up the excellent work!"<<endl;
                    return;
                }
                break;
            case 2:
                // Call customer menu
                returnChoice = customerLogSign();
                if(returnChoice == 0){
                    cout<<"\nThank you for visiting our shop! We hope to see you again soon."<<endl;
                    return;
                }
                break;
        }
    }
}

int Shop :: staffLogSign(){
    user = new Staff();
    int choice, returnChoice;
    bool isLogin = false;
    bool isSignUp = false;
    while(!isLogin){
        choice = UI.logSignUI();
        string username, password;
        switch (choice){
            case 0:
                return 0;
            case 1:
                UI.loginUI(username, password);
                isLogin = user->login(username, password);
                if(!isLogin){
                    UI.failLogin();
                }else{
                    UI.successLogin(username);
                    returnChoice = staffMenu();
                    return returnChoice;
                }
                break;
            case 2:
                UI.signUpUI(username, password);
                isSignUp = user->signUP(username, password);
                if(!isSignUp){
                    UI.failSignUP();
                }else{
                    isLogin = true;
                    UI.successSignUP(username);
                    returnChoice = staffMenu();
                    return returnChoice;
                }
                break;
            case 3:
                return 3;
        }
    }
    return 0;
}

int Shop :: customerLogSign(){
    user = new Customer();
    int choice, returnChoice;
    bool isLogin = false;
    bool isSignUp = false;
    while(!isLogin){
        choice = UI.logSignUI();
        string username, password;
        switch (choice){
            case 0:
                return 0;
            case 1:
                UI.loginUI(username, password);
                isLogin = user->login(username, password);
                if(!isLogin){
                    UI.failLogin();
                }else{
                    UI.successLogin(username);
                    returnChoice = customerMenu();
                    return returnChoice;
                }
                break;
            case 2:
                UI.signUpUI(username, password);
                isSignUp = user->signUP(username, password);
                if(!isSignUp){
                    UI.failSignUP();
                }else{
                    isLogin = true;
                    UI.successSignUP(username);
                    returnChoice = customerMenu();
                    return returnChoice;
                }
                break;
            case 3:
                return 3;
        }
    }
    return 0;
}

int Shop :: staffMenu(){
    return 1;
}

int Shop :: customerMenu(){
    Pastry selectedPastry, deletePastry;
    int choice, selectItem, buyMethod, viewCartOption, returnChoice;
    float piece, weight;
    while(true){
        choice = UI.customerMenuDisplay();
        switch(choice){
            case 0:

                return 0;
                break;
            case 1:
                selectItem = UI.customerFoodMenuDisplay(inventory);
                if(selectItem == -1){
                    break;
                }
                buyMethod = UI.customerFoodBuyMethod();
                selectedPastry = inventory.getPastryList()[selectItem-1];
                if(buyMethod == 1){
                    piece = UI.customerBuyByPiece(selectedPastry);
                    selectedPastry.setPiece(piece);
                }else if(buyMethod == 2){
                    weight = UI.customerBuyByWeight(selectedPastry);
                    selectedPastry.setWeight(weight);
                }
                // Reduce inventory
                inventory.getPastryList()[selectItem-1] -= selectedPastry;
                // Add to Cart
                static_cast<Customer*>(user)->getCart().addToCart(selectedPastry);
                break;
            case 2:
                while(true){
                    viewCartOption = UI.displayCart(static_cast<Customer*>(user)->getCart());
                    if(viewCartOption == 1){ // Delete item
                        int deleteItemNo = UI.deleteCartItem(static_cast<Customer*>(user)->getCart());
                        if(deleteItemNo == -1){
                            continue;
                        }
                        // add back to inventory before deleting
                        inventory.addLocalInventory(static_cast<Customer*>(user)->getCart().getInCartItem()[deleteItemNo-1]);
                        // delete from cart
                        static_cast<Customer*>(user)->getCart().deleteFromCart(deleteItemNo);
                    }else if(viewCartOption == 2){ // Payment
                        returnChoice = customerPayment();
                        if(returnChoice == 3){
                            break;
                        }
                        return returnChoice;
                    }else{
                        break;
                    }
                }
                break;
        }
    }
    return 0;
}

int Shop :: customerPayment(){
    int choice;
    choice = UI.customerPaymentPage();
    return 0;
}