#include "view.h"
#include "inventory.h"
#include "pastry.h"
#include "cart.h"
#include <iostream>
#include <fstream>
#include <iomanip>
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


void View :: displayPastryMenu() {
    string type, name;
    float price;
    int amount, counter=1,choice;



    cout<< "-----------------------------------------------------" << "\n"
        << "|      Item            Price           Amount       |" << "\n"
        << "-----------------------------------------------------" << "\n";

//itemName pricePiece priceWeight amount score comment
    fstream input("inventory.txt", ios::in);
    while (input>>name>>price>>amount) {
        cout << "  " << counter << ". " << setw(15) << left << name
            << setw(6) << right << price
            << setw(15) << right << amount << endl;
        counter++;
    }
}

void View :: editPromo(){
    cout<< "-----------------------------------------------------" << "\n"
        << "|               Promotion Of The Day                 |" << "\n"
        << "-----------------------------------------------------" << "\n"
        << "|             For every 5 purchases made             |" << "\n"
        << "|             Will get a 10%% discount!              |" << "\n"
        << "-----------------------------------------------------" << "\n";
}

void View :: checkPromo(){
    cout<< "-----------------------------------------------------" << "\n"
        << "|               Promotion Of The Day                 |" << "\n"
        << "-----------------------------------------------------" << "\n"
        << "|             For every 5 purchases made             |" << "\n"
        << "|             Will get a 10%% discount!              |" << "\n"
        << "-----------------------------------------------------" << "\n";
}


 int View :: payment(const Cart& cart, int userPurchaseCount){
    int choice;

    cout<< "-----------------------------------------------------" << "\n"
        << "|                      Checkout                      |"<< "\n"
        << "-----------------------------------------------------" << "\n"
        << "|      Item            Price           Amount        |"<< "\n"
        << "-----------------------------------------------------" << "\n";
    // call cart function
    for(int i = 0; i < cart.getAmount(); i++){
        cout<< "|                                                    |"<< "\n";
        string itemName = cart.getInCartItem()[i].getFlavour() + " " + cart.getInCartItem()[i].getType();
        if(itemName.length() >= 20){
            itemName = itemName.substr(0, 20) + "...";
        }
        cout << "|   ";
        cout << setw(20) << left << itemName << " "
             << setw(10) << fixed << setprecision(2) << showpoint << cart.getInCartItem()[i].getPrice()
             << setw(19) << right << to_string(static_cast<int>(cart.getInCartItem()[i].getPiece())) + "          |" << endl;
        cout<< "|                                                    |"<< "\n";
    }
    // call payment function to calculate the total price and discount
    float total;
    bool gotDiscount = false;
    total = cart.getTotalPrice(userPurchaseCount, gotDiscount);
    if(!gotDiscount){
        cout<< "-----------------------------------------------------" << "\n"
            << "|    Total: " << setw(32) << fixed << setprecision(2) << showpoint << right << total << "         |\n"
            << "-----------------------------------------------------" << "\n";
    }else{
        cout<< "-----------------------------------------------------" << "\n"
            << "|    Total: " << setw(32) << fixed << setprecision(2) << showpoint << right << total/0.9 << "         |\n"
            << "|-Discount: " << setw(32) << fixed << setprecision(2) << showpoint << right << total/0.9*0.1 << "         |\n"
            << "|   =Final: " << setw(32) << fixed << setprecision(2) << showpoint << right << total << "         |\n"
            << "-----------------------------------------------------" << "\n";
    }
    do{
        cout << "Pay?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "Your choice: ";
        cin >> choice;
    }while(validateInput(choice, 1, 2));
    return choice;
 }

//extra function tbc
 void View :: checkSales(){

 }


bool View :: validatePieceAndWeight(float userInput, float max){
    if(userInput > 0.0 && userInput <= max){
        return false;
    }else{
        cout << endl;
        cout << "Oops! Unable to add into cart. Limited stocks available: " << max << "." << endl;
        cout << endl;
        return true;
    }
}

bool View :: validateOutofStock(int userInput, const Inventory &inventory){
    Pastry* pastryList = inventory.getPastryList();
    if(pastryList[userInput-1].getPiece() <= 0){
        cout << endl;
        cout << "Item sold out! Please select other variation." << endl;
        return true;
    }
    return false;
}

int View :: mainmenu(){
    int choice;
    do{
        cout << "-----------------------------------------------------" << "\n"
             << "|      Welcome to My Eid Cookies and Cakes Hub       |"<< "\n"
             << "-----------------------------------------------------" << "\n"
             << "| Please enter (0-2):                                |"<< "\n"
             << "| 0. Exit                                            |"<< "\n"
             << "| 1. Staff                                           |"<< "\n"
             << "| 2. Customer                                        |"<< "\n"
             << "-----------------------------------------------------" << endl;
        cout << "Your choice: ";
        cin >> choice;
    }while(validateInput(choice, 0, 2));
    return choice;
}

int View :: logSignUI(){
    int choice;
    do{
        cout << "-----------------------------------------------------" << "\n"
             << "|                   Login / SignUp                   |"<< "\n"
             << "-----------------------------------------------------" << "\n"
             << "| Please enter (0-2):                                |"<< "\n"
             << "| 1. Login                                           |"<< "\n"
             << "| 2. Signup                                          |"<< "\n"
             << "| 3. Back to Choose Role                             |"<< "\n"
             << "-----------------------------------------------------" << endl;
        cout << "Your choice: ";
        cin >> choice;
    }while(validateInput(choice, 1, 3));
    return choice;
}

int View :: staffMenuDisplay(){
    int choice;
    do{
        cout << "-----------------------------------------------------" << "\n"
             << "|               Staff Operations Menu                |"<< "\n"
             << "-----------------------------------------------------" << "\n"
             << "| 0. Exit                                            |"<< "\n"
             << "| 1. Menu                                            |"<< "\n"
             << "| 2. Inventory                                       |"<< "\n"
             << "| 3. Check Sales                                     |"<< "\n"
             << "-----------------------------------------------------" << endl;
        cout << "Your choice: ";
        cin >> choice;
    }while(validateInput(choice, 0, 3));
    return choice;
}

int View :: customerMenuDisplay(){
    int choice;
    do{
        cout<< "-----------------------------------------------------"  << "\n"
            << "|             Eid Cookies and Cakes Hub              |" << "\n"
            << "-----------------------------------------------------"  << "\n"
            << "| 0. Exit                                            |" << "\n"
            << "| 1. Menu                                            |" << "\n"
            << "| 2. Cart                                            |" << "\n"
            << "| 3. Promotion                                       |" << "\n"
            << "-----------------------------------------------------"  << endl;

        cout << "Your choice: ";
        cin >> choice;
    }while(validateInput(choice, 0, 3));
    return choice;
}

void View :: loginUI(string &username, string &password){

    cout << "-----------------------------------------------------" << "\n"
         << "|                       Login                        |"<< "\n"
         << "-----------------------------------------------------" << "\n"
         << " Enter your username: ";
    cin >> username;
    cout << " Enter your password: ";
    cin >> password;
    cout << "-----------------------------------------------------" << endl;
    
}

void View :: signUpUI(string &username, string &password){
    cout << "-----------------------------------------------------" << "\n"
         << "|                       Sign Up                      |"<< "\n"
         << "-----------------------------------------------------" << "\n"
         << " Enter your username: ";
    cin >> username;
    cout << " Enter new password: ";
    cin >> password;
         
}

void View :: failLogin(){
    cout << endl;
    cout << "Your username or password is incorrect. Please try again."<<"\n"
         << "-----------------------------------------------------" << endl;
}

void View :: failSignUP(){
    cout << endl;
    cout << "Your username has been used. Please try again."<<"\n"
         << "-----------------------------------------------------" << endl;
}

void View :: successLogin(string username){
    cout << endl;
    cout << "Login successfully. Welcome " << username <<"\n"
         << "-----------------------------------------------------" << endl;
}

void View :: successSignUP(string username){
    cout << endl;
    cout << "Sign up successfully. Welcome " << username <<"\n"
         << "-----------------------------------------------------" << endl;
}

void View :: successPaid(string username){
    cout << "-----------------------------------------------------" << endl;
    cout << "Thank you for your payment. Have a nice day " << username << " !\n";
}

int View :: customerFoodMenuDisplay(const Inventory &inventory){
    int choice = -1;
    int totalItemNumber;
    if(!inventory.checkAllEmpty()){
        do{
            cout << endl;
            cout << "---------------------------------------------------------" << "\n"
                 << "|                          Menu                          |"<< "\n"
                 << "---------------------------------------------------------" << "\n";
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
            cout << "---------------------------------------------------------" << endl;
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
        cout << "Purchase by" << endl;
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
    cout << "---------------------------------------------------------" << "\n"
         << "|                          Cart                          |"<< "\n"
         << "---------------------------------------------------------" << "\n";
    for(int i = 0; i < customerCart.getAmount(); i++){
        cout << i+1 << ". " 
                << cartList[i].getFlavour() 
                << " " << cartList[i].getType() 
                << " RM" << cartList[i].getPrice()
                << endl;
    }
    cout << "---------------------------------------------------------"<< "\n";
    int choice;
    do{
        cout << endl;
        cout << "-------------------------------------" << "\n"
             << "|           Operation Menu           |" << "\n"
             << "-------------------------------------" << "\n"
             << "|    1. Remove item                  |"<< "\n"
             << "|    2. Proceed to payment           |" << "\n"
             << "|    3. Return to Customer Menu      |" << "\n"
             << "-------------------------------------" << "\n"
             << "Select operation: ";
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