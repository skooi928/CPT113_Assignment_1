#include <iostream>
#include "user.h"
#include "service.h"
#include "pastry.h"
#include "receipt.h"
#include "rating.h"
using namespace std;

void start(int&); // Start the UI
void accountCheck(int&); // Login/Signup

int main(){
    // Program continuation
    char cont = 'y';
    while(cont == 'y' || cont == 'Y'){
        int choice1, choice2;
        // Using pointer to allocate memory because we don't know if the user is staff or customer
        User* user = nullptr;
        // Start the program
        start(choice1);
        cout << endl; // For better spacing, good looking and organized UI
        accountCheck(choice2);
        cout << endl; // For better spacing, good looking and organized UI
        // Deciding which user role to give
        if(choice1 == 1){
            if(choice2 == 2){
                user = new Staff();
                // staff SIGNUP
                user->signUP(choice1);
            }else{
                // staff LOGIN
                string staffUsername;
                string staffPassword;
                cout << "Enter Your Username: ";
                cin >> staffUsername;
                cout << "Enter Your Password: ";
                cin >> staffPassword;
                user = new Staff(staffUsername, staffPassword);
            }
        }else if(choice1 == 2){
            if(choice2 == 2){
                user = new Customer();
                // customer SIGNUP
                user->signUP(choice1);
            }else{
                // customer LOGIN
                string customerUsername;
                string customerPassword;
                cout << "Enter Your Username: ";
                cin >> customerUsername;
                cout << "Enter Your Password: ";
                cin >> customerPassword;
                user = new Customer(customerUsername, customerPassword);
            }
        }else{
            cout << "Incorrect Input! Only 1 or 2 is accepted. Please try again!" << endl;
        }
        if((choice1 == 1 || choice1 == 2) && choice2 != 2){
            bool notLogin;
            user->login(notLogin);
            // User doesn't have any account or record, ask them to sign up
            if(notLogin){
                cout << "Your account is not found!" << endl;
                cout << "Please sign up here: " << endl;
                cout << endl;
                user->signUP(choice1);
            }
        }
        cout << endl;
        cout << "Continue? (y/n): ";
        cin >> cont;
    }
    return 0;
}

void start(int& choice){
    cout << "Welcome to My Eid Cookies and Cakes Hub" << endl;
    cout << endl;
    cout << "Please enter (1-2):" << endl;
    cout << "1. Staff" << endl;
    cout << "2. Customer" << endl;
    cout << "Your role? ";
    cin >> choice;
}

void accountCheck(int& choice){
    cout << "Login/Signup?" << endl;
    cout << "1. Login" << endl;
    cout << "2. Signup" << endl;
    cout << "Your choice: ";
    cin >> choice;
}