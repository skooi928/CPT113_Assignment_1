#include "View.h"
#include <iostream>
#include<fstream>
#include<iomanip>
using namespace std;

void View :: start(int& choice){
    cout << "Welcome to My Eid Cookies and Cakes Hub" << endl;
    cout << endl;
    cout << "Please enter (1-2):" << endl;
    cout << "1. Staff" << endl;
    cout << "2. Customer" << endl;
    cout << "Your role? ";
    cin >> choice;
}

void View :: accountCheck(int& choice){
    cout << "Login/Signup?" << endl;
    cout << "1. Login" << endl;
    cout << "2. Signup" << endl;
    cout << "3. Back to Choose Role" << endl;
    cout << "Your choice: ";
    cin >> choice;
}

void View :: menuCustomer() {
    cout << "-----------------------------------------------------" << "\n"
        << "|             Eid Cookies and Cakes Hub              |" << "\n"
        << "-----------------------------------------------------" << "\n"
        << "| 1. Check Promotion                                 |" << "\n"
        << "| 2. Shopping Cart                                   |" << "\n"
        << "| 3. Payment                                         |" << "\n"
        << "| 4. Exit                                            |" << "\n"
        << "-----------------------------------------------------" << endl;
}

void View :: menuWorker() {
    cout << "-----------------------------------------------------" << "\n"
        << "|             Eid Cookies and Cakes Hub              |" << "\n"
        << "-----------------------------------------------------" << "\n"
        << "| 1. Edit Menu                                       |" << "\n"
        << "| 2. Edit Promotion                                  |" << "\n"
        << "| 3. Check Sales                                     |" << "\n"
        << "| 4. Exit                                            |" << "\n"
        << "-----------------------------------------------------" << endl;
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

void View :: editMenu() {
    int choice,operation;
    cout << "Enter index of pastry you would like to select: ";

    //after tht need to add input validation
    cin >> choice;

    cout<< "  " << "1. Edit Name" << "\n"
        << "  " << "2. Edit Price" << "\n"
        << "  " << "3. Edit Amount" << endl;

    switch (operation) {
    case 1:
        // call editName(int) func in service
        break;

    case 2:
        // call editPrice(int) func in service
        break;

    case 3:
        // call editAmount(int) func in service
        break;

    default:
        cout << "Invalid Input!"<<endl;
        break;

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


 void View :: payment(){
    cout<< "-----------------------------------------------------" << "\n"
        << "|               Promotion Of The Day                 |"<< "\n"
        << "-----------------------------------------------------" << "\n"
        << "|      Item            Price           Amount        |"<< "\n"
        << "-----------------------------------------------------" << "\n";
    // call cart function to display item inside the cart
        
 }

//extra function tbc
 void View :: checkSales(){
 }

 void View :: exit(){




 }