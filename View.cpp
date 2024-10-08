#include "View.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_STREAM_SIZE = 32767;

// A helper function to validate the input
bool View::validateInput(int userInput, int min, int max) {
    // if cin.fail() to check if the input is invalid, different data type input
    // !cin.fail() to check if the input is valid
    if (!(cin.fail()) && userInput >= min && userInput <= max) {
        return false;
    }
    else {
        cout << endl;
        cout << "ERROR: Input must be from " << min << " to " << max << "." << endl;
        cout << endl;
        // since the input might be char for int type, so we need to clear the error flag
        cin.clear();
        // and clear any input buffer
        cin.ignore(MAX_STREAM_SIZE, '\n');
        return true;
    }
}

void View::checkPromo() {
    // To show the promo message
    cout << endl;
    cout << "-----------------------------------------------------" << "\n"
         << "|                Promotion Of The Day                |" << "\n"
         << "-----------------------------------------------------" << "\n"
         << "|                First time purchase                 |" << "\n"
         << "|                                                    |" << "\n"
         << "|                        AND                         |" << "\n"
         << "|                                                    |" << "\n"
         << "|             For every 5 purchases made             |" << "\n"
         << "|                                                    |" << "\n"
         << "|            YOU WILL GET A 10% DISCOUNT!            |" << "\n"
         << "-----------------------------------------------------" << "\n";
}


int View::payment(const Cart& cart, int userPurchaseCount) {
    int choice;
    cout << endl;
    cout << "----------------------------------------------------" << "\n"
        << "|                      Checkout                      |" << "\n"
        << "-----------------------------------------------------" << "\n"
        << "|      Item            Price           Amount        |" << "\n"
        << "-----------------------------------------------------" << "\n";
    // call Cart getter function to get all information needed
    for (int i = 0; i < cart.getAmount(); i++) {
        cout << "|                                                    |" << "\n";
        string itemName = cart.getInCartItem()[i].getFlavour() + " " + cart.getInCartItem()[i].getType();
        // Check if item name too long put ... at the back to prevent display error
        if (itemName.length() >= 20) {
            itemName = itemName.substr(0, 20) + "...";
        }
        cout << "|  ";
        cout << setw(20) << left << itemName << "RM"
            << setw(10) << fixed << setprecision(2) << showpoint << cart.getInCartItem()[i].getPrice()
            << setw(19) << right << to_string(static_cast<int>(cart.getInCartItem()[i].getPiece())) + "          |" << endl;
        cout << "|                                                    |" << "\n";
    }
    float total;
    bool gotDiscount = false;
    // call payment function to calculate the total price and discount
    total = cart.getTotalPrice(userPurchaseCount, gotDiscount);
    // Different cases of output if got discount or not
    if (!gotDiscount) {
        cout << "-----------------------------------------------------" << "\n"
            << "     Total: " << setw(13) << fixed << setprecision(2) << showpoint << right << "RM" << total << "\n"
            << "-----------------------------------------------------" << "\n";
    }
    else {
        cout << "-----------------------------------------------------" << "\n"
            << "     Total: " << setw(13) << fixed << setprecision(2) << showpoint << right << "RM" << total / 0.9 << "\n"
            << "- Discount: " << setw(13) << fixed << setprecision(2) << showpoint << right << "RM" << total / 0.9 * 0.1 << "\n"
            << "=    Final: " << setw(13) << fixed << setprecision(2) << showpoint << right << "RM" << total << "\n"
            << "-----------------------------------------------------" << "\n";
    }
    do {
        cout << "Pay?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "Your choice: ";
        cin >> choice;
    } while (validateInput(choice, 1, 2));
    return choice;
}

bool View::validatePieceAndWeight(float userInput, float max) {
    if (!(cin.fail()) && userInput > 0.0 && userInput <= max) {
        return false;
    }
    else {
        // Show max value of item they can add.
        cout << endl;
        cout << "Oops! Unable to add into cart. Limited stocks available: " << max << "." << endl;
        cout << endl;
        cin.clear();
        cin.ignore(MAX_STREAM_SIZE, '\n');
        return true;
    }
}

// Another helper function to validate the out of stock
bool View::validateOutofStock(int userInput, const Inventory& inventory) {
    Pastry* pastryList = inventory.getPastryList();
    // If user still choice the items out of stock, it will display item sold out
    if (pastryList[userInput - 1].getPiece() <= 0) {
        cout << endl;
        cout << "Item sold out! Please select other variation." << endl;
        return true;
    }
    return false;
}

//Display menu for selling Eid cookies and cakes 
int View::mainmenu() {
    int choice = -1;
    do {
        cout << endl;
        cout << "-----------------------------------------------------" << "\n"
            << "|      Welcome to My Eid Cookies and Cakes Hub       |" << "\n"
            << "-----------------------------------------------------" << "\n"
            << "| Please enter (0-2):                                |" << "\n"
            << "| 0. Exit                                            |" << "\n"
            << "| 1. Staff                                           |" << "\n"
            << "| 2. Customer                                        |" << "\n"
            << "-----------------------------------------------------" << endl;
        cout << "Your choice: ";
        cin >> choice;
    } while (validateInput(choice, 0, 2)); // Call validateInput() to ensure user's input is within the range (0-2) in this case
    // if input is not valid, return true and the loop continues
    return choice;
}

int View::logSignUI() {
    int choice;
    do {
        cout << endl;
        cout << "-----------------------------------------------------" << "\n"
            << "|                   Login / SignUp                   |" << "\n"
            << "-----------------------------------------------------" << "\n"
            << "| Please enter (1-3):                                |" << "\n"
            << "| 1. Login                                           |" << "\n"
            << "| 2. Signup                                          |" << "\n"
            << "| 3. Back to Choose Role                             |" << "\n"
            << "-----------------------------------------------------" << endl;
        cout << "Your choice: ";
        cin >> choice;
    } while (validateInput(choice, 1, 3));
    return choice;
}

int View::staffMenuDisplay() {
    int choice = -1;
    do {
        cout << endl;
        cout << "-----------------------------------------------------" << "\n"
            << "|               Staff Operations Menu                |" << "\n"
            << "-----------------------------------------------------" << "\n"
            << "| 0. Exit                                            |" << "\n"
            << "| 1. Inventory                                       |" << "\n"
            << "| 2. Edit Inventory                                  |" << "\n"
            << "| 3. Add New Item                                    |" << "\n"
            << "-----------------------------------------------------" << endl;
        cout << "Your choice: ";
        cin >> choice;
    } while (validateInput(choice, 0, 3));
    return choice;
}

int View::customerMenuDisplay() {
    int choice = -1;
    do {
        cout << endl;
        cout << "-----------------------------------------------------" << "\n"
            << "|             Eid Cookies and Cakes Hub              |" << "\n"
            << "-----------------------------------------------------" << "\n"
            << "| 0. Exit                                            |" << "\n"
            << "| 1. Menu                                            |" << "\n"
            << "| 2. Cart                                            |" << "\n"
            << "| 3. Promotion                                       |" << "\n"
            << "-----------------------------------------------------" << endl;

        cout << "Your choice: ";
        cin >> choice;
    } while (validateInput(choice, 0, 3));
    return choice;
}

void View::loginUI(string& username, string& password) {
    cout << endl;
    cout << "-----------------------------------------------------" << "\n"
        << "|                       Login                        |" << "\n"
        << "-----------------------------------------------------" << "\n"
        << " Enter your username: ";
    cin >> username;
    cout << " Enter your password: ";
    cin >> password;
    cout << "-----------------------------------------------------" << endl;

}

void View::signUpUI(string& username, string& password) {
    cout << endl;
    cout << "-----------------------------------------------------" << "\n"
        << "|                       Sign Up                      |" << "\n"
        << "-----------------------------------------------------" << "\n"
        << " Enter your username: ";
    cin >> username;
    cout << " Enter new password: ";
    cin >> password;

}

void View::failLogin() {
    cout << endl;
    cout << "Your username or password is incorrect. Please try again." << "\n"
        << "-----------------------------------------------------" << endl;
}

void View::failSignUP() {
    cout << endl;
    cout << "Your username has been used. Please try again." << "\n"
        << "-----------------------------------------------------" << endl;
}

void View::successLogin(string username) {
    cout << endl;
    cout << "Login successfully. Welcome " << username << "\n"
        << "-----------------------------------------------------" << endl;
}

void View::successSignUP(string username) {
    cout << endl;
    cout << "Sign up successfully. Welcome " << username << "\n"
        << "-----------------------------------------------------" << endl;
}

void View::successPaid(string username) {
    cout << "-----------------------------------------------------" << endl;
    cout << "Thank you for your payment. Have a nice day " << username << " !\n";
}

void View::staffFoodMenuDisplay(const Inventory& inventory) {
    cout << endl;
    cout << "---------------------------------------------------------" << "\n"
        << "|                      Inventory                          |" << "\n"
        << "----------------------------------------------------------" << "\n";
    if(inventory.checkAllEmpty()){
        cout << "No item in the inventory." << endl;
    }
    Pastry* pastryList = inventory.getPastryList();
    int totalItemNumber = inventory.getItemNumber();
    for (int i = 0; i < totalItemNumber; i++) {
        cout << i + 1 << ". "
            << pastryList[i].getFlavour()
            << " " << pastryList[i].getType()
            << " " << pastryList[i].getPiece() << "pieces"
            << " " << pastryList[i].getWeight() << "kg"
            << " RM" << pastryList[i].getPPW() << "/kg RM"
            << pastryList[i].getPPP() << "/pc";
        cout << endl;
    }
    cout << "---------------------------------------------------------" << endl;

}

int View::readItemIdx(const Inventory& inventory) {
    int idx = -1; // index = -1 to check if inventory is empty
    if(!(inventory.checkAllEmpty())){
        do {
            cout << "Enter index of item you would like to edit: ";
            cin >> idx;

        } while (validateInput(idx, 1, inventory.getItemNumber()));
    }
    return idx;
}

int View::inventoryEditDisplay(Inventory& inventory, int idx) {
    int choice;
    float weightperpiece, priceperweight, piece, weight;
    string type, flavour;
    if(idx != -1){
        do {
            cout << endl;
            cout<< "-----------------------------------------------------" << "\n"
                << "|                   Operation Menu                   |" << "\n"
                << "-----------------------------------------------------" << "\n"
                << "| 0. Exit                                            |" << "\n"
                << "| 1. Type                                            |" << "\n"
                << "| 2. Flavour                                         |" << "\n"
                << "| 3. Piece                                           |" << "\n"
                << "| 4. Weight                                          |" << "\n"
                << "| 5. Price Per Weight                                |" << "\n"
                << "-----------------------------------------------------" << endl;
            cout << "Select operations: ";
            cin >> choice;
        } while (validateInput(choice, 0, 5));

        Pastry* pastryList = inventory.getPastryList();
        switch (choice) {
        case 0:
            return 0;
            break;
        case 1:
            do {
                cout << "Type: ";
                cin >> type;
            } while (editInfoValidation(type));
            pastryList[idx - 1].setType(type);
            break;
        case 2:
            cout << "Flavour: ";
            cin >> flavour;
            pastryList[idx - 1].setFlavour(flavour);
            break;
        case 3:
            do {
                cout << "Piece: ";
                cin >> piece;
            } while (editInfoValidation(piece));
            pastryList[idx - 1].setPiece(piece);
            pastryList[idx - 1].setWPP(pastryList[idx - 1].getWeight()/piece);
            break;
        case 4:
            do {
                cout << "Weight: ";
                cin >> weight;
            } while (editInfoValidation(weight));
            pastryList[idx - 1].setWeight(weight);
            pastryList[idx - 1].setWPP(weight/pastryList[idx - 1].getPiece());
            break;
        case 5:
            do {
                cout << "Price Per Weight: ";
                cin >> priceperweight;
            } while (editInfoValidation(priceperweight));
            pastryList[idx - 1].setPPW(priceperweight);
            break;
        }
    }else{
        cout << endl << "There's no item in the inventory! You cannot edit anything!" << endl;
    }
    return 1;
}

bool View::editInfoValidation(string type) {
    if (type != "Cookie" && type != "Cake") {
        cout << "Invalid input. Enter Cookie or Cake only." << endl;
        return true;
    }
    return false;
}

bool View::editInfoValidation(float num) {
    if (num < 0.0) {
        cout << "Value must be greater or equal to 0" << endl;
        return true;
    }
    return false;
}

void View::addNewItem(Pastry& newPastry, const Inventory& inventory) {
    float weightperpiece, priceperweight, piece, weight;
    string type, flavour;
    cout << endl;
    cout << "-----------------------------------------------------" << "\n"
        << "|              Enter Info of New Item                |" << "\n"
        << "-----------------------------------------------------" << endl;
    do {
        cout << "Type: ";
        cin >> type;
    } while (editInfoValidation(type));

    cout << "Flavour: ";
    cin >> flavour;

    do {
        cout << "How Many Pieces Available: ";
        cin >> piece;
    } while (editInfoValidation(piece));


    do {
        cout << "Weight Per Piece: ";
        cin >> weightperpiece;
    } while (editInfoValidation(weightperpiece));

    do {
        cout << "Price Per Weight: ";
        cin >> priceperweight;
    } while (editInfoValidation(priceperweight));

    weight = piece * weightperpiece;

    newPastry.setPastryValue(type, flavour, weightperpiece, priceperweight, piece, weight);

}

// To show status message of item added or not
void View::addStatusDisplay(bool status) {
    if (status)
        cout << "\nItem has been added successsfully.";
    else
        cout << "\nItem existed fail to add the item.";
}

int View::customerFoodMenuDisplay(const Inventory& inventory) {
    int choice = -1;
    int totalItemNumber;
    if (!inventory.checkAllEmpty()) { // Inventory is not empty, then only the user can buy item from our shop
        do {
            cout << endl;
            cout << "---------------------------------------------------------" << "\n"
                << "|                          Menu                          |" << "\n"
                << "---------------------------------------------------------" << "\n";
            Pastry* pastryList = inventory.getPastryList();
            totalItemNumber = inventory.getItemNumber();
            cout << "0. Return to customer menu\n";
            for (int i = 0; i < totalItemNumber; i++) {
                cout << i + 1 << ". "
                    << pastryList[i].getFlavour()
                    << " " << pastryList[i].getType()
                    << " RM" << pastryList[i].getPPW() << "/kg RM"
                    << pastryList[i].getPPP() << "/pc";
                // When pastryList in inventory class object is run out of cake or cookie will display out of stock
                if (pastryList[i].getPiece() <= 0) {
                    cout << " (Out of Stock!)";
                }
                cout << "\n";
            }
            cout << "---------------------------------------------------------" << endl;
            cout << "Enter index of item to add into cart: ";
            cin >> choice;
            if (choice == 0)
                return 0;
        } while (validateInput(choice, 1, totalItemNumber) || validateOutofStock(choice, inventory)); // Except from checking the input in range,
                                                                                                      // check if the item is out of stock
    }
    else { // else show error message that our shop has nothing in stock already.
        cout << endl;
        cout << "ERROR: Our shop currently has no items available." << endl;
    }
    return choice;
}

int View::customerFoodBuyMethod() { // Freedom for the customer to buy by weight or by piece.
    int choice;
    do {
        cout << endl;
        cout << "-------------------------------------" << "\n"
            << "|           Purchase Method          |" << "\n"
            << "-------------------------------------" << "\n"
            << "|    1. Piece(pc)                    |" << "\n"
            << "|    2. Weight(kg)                   |" << "\n"
            << "-------------------------------------" << "\n";
        cout << "Your choice: ";
        cin >> choice;
    } while (validateInput(choice, 1, 2));
    return choice;
}

float View::customerBuyByPiece(Pastry& itemSelected) {
    float piece;
    do {
        cout << endl;
        cout << "How many pieces do you want: ";
        cin >> piece;
    } while (validatePieceAndWeight(piece, itemSelected.getPiece()));
    return piece;
}

float View::customerBuyByWeight(Pastry& itemSelected) {
    float weight;
    do {
        cout << endl;
        cout << "How many kg do you want: ";
        cin >> weight;
    } while (validatePieceAndWeight(weight, itemSelected.getWeight()));
    return weight;
}

int View::displayCart(const Cart& customerCart) {
    Pastry* cartList = customerCart.getInCartItem();
    cout << endl;
    cout << "---------------------------------------------------------" << "\n"
        << "|                          Cart                          |" << "\n"
        << "---------------------------------------------------------" << "\n";

    if (customerCart.getAmount() == 0) { // Display empty cart message
        cout << "The Cart is Empty Nothing to See Here" << endl;
    }

    for (int i = 0; i < customerCart.getAmount(); i++) {
        cout << i + 1 << ". "
            << cartList[i].getFlavour()
            << " " << cartList[i].getType()
            << " RM" << cartList[i].getPrice()
            << endl;
    }
    cout << "---------------------------------------------------------" << "\n";
    int choice;
    do {
        cout << endl;
        cout << "-------------------------------------" << "\n"
            << "|           Operation Menu           |" << "\n"
            << "-------------------------------------" << "\n"
            << "|    1. Remove item                  |" << "\n"
            << "|    2. Proceed to payment           |" << "\n"
            << "|    3. Return to Customer Menu      |" << "\n"
            << "-------------------------------------" << "\n"
            << "Select operation: ";
        cin >> choice;
    } while (validateInput(choice, 1, 3));
    return choice;
}

int View::deleteCartItem(const Cart& customerCart) {
    int choice = -1;
    if (customerCart.getAmount() != 0) {
        do {
            cout << endl;
            cout << "Which item do you want to delete: ";
            cin >> choice;
        } while (validateInput(choice, 1, customerCart.getAmount()));
    }
    else {
        cout << endl;
        cout << "ERROR: Your cart is empty. You must have an item in your cart to delete!" << endl;
    }
    return choice;
}

// Display and confirm whether the user wants to exit the program and return true to exit the program and vice-versa
bool View::exitConfirmation() {
    string isExit;
    cout << endl;
    cout << "Press Y/y to exit program: ";
    cin >> isExit;
    cin.ignore(MAX_STREAM_SIZE, '\n');
    if (isExit == "Y" || isExit == "y") {
        return true;
    }
    return false;
}
