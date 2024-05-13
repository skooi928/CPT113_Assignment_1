#include "view.h"
#include "inventory.h"
#include "pastry.h"
#include <iostream>
#include <string>
using namespace std;

bool View :: validateInput(int userInput, int min, int max){
    if(userInput >= min && userInput <= max){
        return false;
    }else{
        cout << endl;
        cout << "ERROR: Input must be from " << min <<  " to " << max << "." << endl;
        cout << endl;
        return true;
    }
}

bool View :: validatePieceAndWeight(float userInput, float max){
    if(userInput > 0.0 && userInput <= max){
        return false;
    }else{
        cout << endl;
        cout << "ERROR: The highest amount of this item we have is " << max << "." << endl;
        cout << endl;
        return true;
    }
}

bool View :: validateOutofStock(int userInput, const Inventory &inventory){
    Pastry* pastryList = inventory.getPastryList();
    if(pastryList[userInput-1].getPiece() <= 0){
        cout << endl;
        cout << "Error! You can't choose item that is out of stock!" << endl;
        return true;
    }
    return false;
}

int View :: mainmenu(){
    int choice;
    do{
        cout << endl;
        cout << "Welcome to My Eid Cookies and Cakes Hub" << endl;
        cout << endl;
        cout << "Please enter (0-2):" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Staff" << endl;
        cout << "2. Customer" << endl;
        cout << "Your choice: ";
        cin >> choice;
    }while(validateInput(choice, 0, 2));
    return choice;
}

int View :: logSignUI(){
    int choice;
    do{
        cout << endl;
        cout << "Login/Signup?" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Login" << endl;
        cout << "2. Signup" << endl;
        cout << "3. Back to Choose Role" << endl;
        cout << "Your choice: ";
        cin >> choice;
    }while(validateInput(choice, 0, 3));
    return choice;
}

int View :: staffMenuDisplay(){
    int choice;
    do{
        cout << endl;
        cout << "Staff" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Inventory" << endl;
        cout << "Your choice: ";
        cin >> choice;
    }while(validateInput(choice, 0, 1));
    return choice;
}

int View :: customerMenuDisplay(){
    int choice;
    do{
        cout << endl;
        cout << "Customer" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Menu" << endl;
        cout << "2. Cart" << endl;
        cout << "Your choice: ";
        cin >> choice;
    }while(validateInput(choice, 0, 2));
    return choice;
}

void View :: loginUI(string &username, string &password){
    cout << endl;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;
}

void View :: signUpUI(string &username, string &password){
    cout << endl;
    cout << "Enter new username: ";
    cin >> username;
    cout << "Enter new password: ";
    cin >> password;
}

void View :: failLogin(){
    cout << endl;
    cout << "Your username or password is incorrect. Please try again." << endl;
}

void View :: failSignUP(){
    cout << endl;
    cout << "Your username has been used. Please try again." << endl;
}

void View :: successLogin(string username){
    cout << endl;
    cout << "Login successfully. Welcome " << username << endl;
}

void View :: successSignUP(string username){
    cout << endl;
    cout << "Sign up successfully. Welcome " << username << endl;
}

int View :: customerFoodMenuDisplay(const Inventory &inventory){
    int choice = -1;
    int totalItemNumber;
    if(!inventory.checkAllEmpty()){
        do{
            cout << endl;
            cout << "Food Menu:" << endl;
            Pastry* pastryList = inventory.getPastryList();
            totalItemNumber = inventory.getItemNumber();
            for(int i = 0; i < totalItemNumber; i++){
                cout << i+1 << ". " 
                    << pastryList[i].getFlavour() 
                    << " " << pastryList[i].getType() 
                    << " RM" << pastryList[i].getPPW() << "/kg RM" 
                    << pastryList[i].getPPP() << "/pc";
                if(pastryList[i].getPiece() <= 0){
                    cout << " (Out of Stock!)";
                }
                cout << endl;
            }
            cout << endl;
            cout << "Enter the number to add the item to your cart: ";
            cin >> choice;
        }while(validateInput(choice, 1, totalItemNumber) || validateOutofStock(choice, inventory));
    }else{
        cout << endl;
        cout << "ERROR: Our shop currently has no items available." << endl;
    }
    return choice;
}

int View :: customerFoodBuyMethod(){
    int choice;
    do{
        cout << endl;
        cout << "Choose your item amount by" << endl;
        cout << "1. Piece(pc)" << endl;
        cout << "2. Weight(kg)" << endl;
        cout << "Your choice: ";
        cin >> choice;
    }while(validateInput(choice, 1, 2));
    return choice;
}

float View :: customerBuyByPiece(Pastry &itemSelected){
    float piece;
    do{
        cout << endl;
        cout << "How many pieces do you want: ";
        cin >> piece;
    }while(validatePieceAndWeight(piece, itemSelected.getPiece()));
    return piece;
}

float View :: customerBuyByWeight(Pastry &itemSelected){
    float weight;
    do{
        
        cout << endl;
        cout << "How many kg do you want: ";
        cin >> weight;
    }while(validatePieceAndWeight(weight, itemSelected.getWeight()));
    return weight;
}

int View :: displayCart(const Cart& customerCart){
    Pastry* cartList = customerCart.getInCartItem();
    for(int i = 0; i < customerCart.getAmount(); i++){
        cout << i+1 << ". " 
                << cartList[i].getFlavour() 
                << " " << cartList[i].getType() 
                << " RM" << cartList[i].getPrice()
                << endl;
    }
    int choice;
    do{
        cout << endl;
        cout << "1. Delete item" << endl;
        cout << "2. Proceed to payment" << endl;
        cout << "3. Back to Customer Menu" << endl;
        cout << "Your choice: ";
        cin >> choice;
    }while(validateInput(choice, 1, 3));
    return choice;
}

int View :: deleteCartItem(const Cart& customerCart){
    int choice = -1;
    if(customerCart.getAmount() != 0){
        do{
            cout << endl;
            cout << "Which item do you want to delete: ";
            cin >> choice;
        }while(validateInput(choice, 1, customerCart.getAmount()));
    }else{
        cout << endl;
        cout << "ERROR: Your cart is empty. You must have an item in your cart to delete!" << endl;
    }
    return choice;
}

int View :: customerPaymentPage(){
    int choice;
    return choice;
}