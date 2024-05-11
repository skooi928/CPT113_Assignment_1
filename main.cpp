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
    bool restart = 1;
    while(cont == 'y' || cont == 'Y'){
        int choice1, choice2, notLogin = 2;
        // Using pointer to allocate memory because we don't know if the user is staff or customer
        User* user = nullptr;
        // Start the program
        start(choice1);
        cout << endl; // For better spacing, good looking and organized UI
        while(restart){
            restart = 0;
            accountCheck(choice2);
            cout << endl; // For better spacing, good looking and organized UI
            // Deciding which user role to give
            if(choice1 == 1){
                user = new Staff();
                if(choice2 == 2){
                    // staff SIGNUP
                    user->signUP(choice1);
                }else{
                    // staff LOGIN
                    user->login(choice1, notLogin);
                }
            }else if(choice1 == 2){
                user = new Customer();
                if(choice2 == 2){
                    // customer SIGNUP
                    user->signUP(choice1);
                }else{
                    // customer LOGIN
                    user->login(choice1, notLogin);
                }
            }else{
                // Input validation
                cout << "Incorrect Input! Only 1 or 2 is accepted. Please try again!" << endl;
            }
            if((choice1 == 1 || choice1 == 2) && choice2 != 2){
                while(notLogin == 1){ // User has correct username but wrong password
                    user->login(choice1, notLogin);
                }
                if(notLogin == 2){ // User doesn't have any account or record, ask them to sign up
                    // Wrong username and password. Ask if wanna login again or signup.
                    cout << "Wrong username and password. Please choose to login again or sign up for a new account." << endl;
                    cout << endl;
                    restart = 1;
                }
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