#include "shop.h"
#include <iostream>
using namespace std;

//Shop constructor
Shop::Shop() {
    user = nullptr;
}

//Shop destructor
Shop :: ~Shop() {
    delete user;
}

void Shop::main() {
    delete user;
    user = nullptr;
    while (true) {
        int choice, returnChoice;
        choice = UI.mainmenu();
        switch (choice) {
            case 0:
                // Call exitConfirmation() in View class to display Y/y to exit program and return true to exit the program 
                if (UI.exitConfirmation()) {
                    cout << "\nThanks for your visiting!" << endl;
                    cout << endl;
                    return;
                }
                // Return false, loop continues 
                break;
    
            case 1:
                // Call staff menu to display login/sign up for staff
                returnChoice = staffLogSign();
                //Display program ended message
                if (returnChoice == 0) {
                    cout << "\nProgram Ended. Keep up the excellent work!" << endl;
                    cout << endl;
                    return;
                }
                break;
            case 2:
                // Call customer menu to display login/sign up for customer 
                returnChoice = customerLogSign();
                //Display program ended message
                if (returnChoice == 0) {
                    cout << "\nThank you for visiting our shop! We hope to see you again soon." << endl;
                    cout << endl;
                    return;
                }
                break;
            default:
                break;
        }
    }
}

int Shop::staffLogSign() {
    // user hold Staff() address 
    user = new Staff();
    int choice, returnChoice;
    // Assign false because haven't login or sign up yet 
    bool isLogin = false;
    bool isSignUp = false;
    while (!isLogin) { // program loop if isLogin false 
        choice = UI.logSignUI(); // Call logSignUI() in View class
        string username, password; 
        switch (choice) {    
        case 1:
            //Staff login
            UI.loginUI(username, password);
            isLogin = user->login(username, password); // Call login() to check if username and password is correct 
            if (!isLogin) {
                //Call failLogin() in View class to display failed login 
                UI.failLogin();
            }
            else {
                //Call successLogin() in View class to display successfully login
                UI.successLogin(username);
                returnChoice = staffMenu();
                return returnChoice;
            }
            break;
        case 2:
            //Staff sign up
            UI.signUpUI(username, password);
            isSignUp = user->signUP(username, password);
            if (!isSignUp) {
                UI.failSignUP();
            }
            else {
                isLogin = true;
                UI.successSignUP(username);
                returnChoice = staffMenu();
                return returnChoice;
            }
            break;
        case 3:
            //Return to role selection menu
            return 3;
        }
    }
    return 0;
}

int Shop::customerLogSign() {
    user = new Customer();
    int choice, returnChoice;
    bool isLogin = false;
    bool isSignUp = false;
    while (!isLogin) {
        choice = UI.logSignUI();
        string username, password;
        switch (choice) {
        case 1:
            //Customer login
            UI.loginUI(username, password);
            isLogin = user->login(username, password);
            if (!isLogin) {
                UI.failLogin();
            }
            else {
                UI.successLogin(username);
                returnChoice = customerMenu();
                return returnChoice;
            }
            break;
        case 2:
            //Customer sign up
            UI.signUpUI(username, password);
            isSignUp = user->signUP(username, password);
            if (!isSignUp) {
                UI.failSignUP();
            }
            else {
                isLogin = true;
                UI.successSignUP(username);
                returnChoice = customerMenu();
                return returnChoice;
            }
            break;
        case 3:
            //Return to role selection menu
            return 3;
        }
    }
    return 0;
}

int Shop::staffMenu() {
    Pastry newPastry;
    int choice, idxItem, editChoice;
    bool confirm=false, status;
    while (true) {
        // Call staffMenuDisplay() in View class to display staff operations menu
        choice = UI.staffMenuDisplay();
        switch (choice) {
            case 0:
                //Exit program
                if (UI.exitConfirmation())
                    return 0;
                break;

            case 1:
                //Call staffFoodMenuDisplay in View Class to display Inventory
                UI.staffFoodMenuDisplay(inventory);
                break;

            case 2:
                // Edit inventory
                UI.staffFoodMenuDisplay(inventory);
                idxItem = UI.readItemIdx(inventory);
                editChoice = UI.inventoryEditDisplay(inventory, idxItem);
                // Update inventory.txt
                inventory.write();
                if (editChoice == 0) {
                    if(UI.exitConfirmation())
                        return 0;
                }
                break;

            case 3:
                //Add new item into inventory
                UI.addNewItem(newPastry, inventory);
                status=inventory.addPastryList(newPastry);
                UI.addStatusDisplay(status);
                // Update inventory.txt
                inventory.write();
                break;

            default:
                break;
        }
    }
    return 0;
}

int Shop::customerMenu() {
    Pastry selectedPastry, deletePastry;
    int choice, selectItem, buyMethod, viewCartOption, returnChoice;
    float piece, weight;
    while (true) {
        choice = UI.customerMenuDisplay();
        switch (choice) {
            case 0:
                //Exit program
                if (UI.exitConfirmation()) {
                    return 0;
                }
                break;
            case 1:
                //Display pastry menu
                selectItem = UI.customerFoodMenuDisplay(inventory);
                if (selectItem <= 0) {
                    break;
                }
                buyMethod = UI.customerFoodBuyMethod();
                selectedPastry = inventory.getPastryList()[selectItem - 1];
                if (buyMethod == 1) {
                    piece = UI.customerBuyByPiece(selectedPastry);
                    selectedPastry.setPiece(piece);
                }
                else if (buyMethod == 2) {
                    weight = UI.customerBuyByWeight(selectedPastry);
                    selectedPastry.setWeight(weight);
                }
                // Reduce inventory
                inventory.getPastryList()[selectItem - 1] -= selectedPastry;
                // Add to Cart
                static_cast<Customer*>(user)->getCart().addToCart(selectedPastry);
                break;
            case 2:
                //Cart operation
                while (true) {
                    viewCartOption = UI.displayCart(static_cast<Customer*>(user)->getCart());
                    if (viewCartOption == 1) { // Delete item

                        if ((static_cast<Customer*>(user)->getCart().getAmount()) == 0) {
                            cout << "The cart is empty! Nothing can be removed.";
                            cout << endl;
                            break;
                        }

                        int deleteItemNo = UI.deleteCartItem(static_cast<Customer*>(user)->getCart());
                        if (deleteItemNo == -1) {
                            continue;
                        }
                        // add back to inventory before deleting
                        inventory.addLocalInventory(static_cast<Customer*>(user)->getCart().getInCartItem()[deleteItemNo - 1]);
                        // delete from cart
                        static_cast<Customer*>(user)->getCart().deleteFromCart(deleteItemNo);
                    }
                    else if (viewCartOption == 2) { // Payment

                        if ((static_cast<Customer*>(user)->getCart().getAmount()) == 0) {
                            cout << "The cart is empty! Add something before proceed to payment.";
                            cout << endl;
                            break;
                        }
                        returnChoice = customerPayment();
                        if (returnChoice == 2) {
                            break;
                        }
                        return returnChoice;
                    }
                    else {
                        break;
                    }
                }
                break;
            case 3:
                //Display details of promotion 
                UI.checkPromo();
                break;

            default:
                break;
        }
    }
    return 0;
}

int Shop::customerPayment() {
    int choice;
    choice = UI.payment(static_cast<Customer*>(user)->getCart(), static_cast<Customer*>(user)->getPurchaseCount());
    switch (choice) {
    case 1:
        // Pay process
        UI.successPaid(user->getUsername());
        // Update customer purchase record
        static_cast<Customer*>(user)->addPurchaseRecord();
        // Inventory update to database
        inventory.write();
        // Cart clear
        static_cast<Customer*>(user)->getCart().clearCart();
        break;
    case 2:
        // Back to customer menu
        return 2;
    }
    return 0;
}