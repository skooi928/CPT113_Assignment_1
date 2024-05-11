#include <iostream>
#include "user.h"
#include "service.h"
#include "pastry.h"
#include "receipt.h"
#include "rating.h"
#include "view.h"
using namespace std;

int main(){
    // Program continuation
    char cont = 'y';
    bool restart = 1, backMainMenu = 1;
    while(cont == 'y' || cont == 'Y'){
        restart = 1; backMainMenu = 1;
        int choice1, choice2, notLogin = 2;
        // Using pointer to allocate memory because we don't know if the user is staff or customer
        User* user = nullptr;
        while(backMainMenu){
            user = new User;
            backMainMenu = 0;
            restart = 1;
            // Start the program
            user->mainmenu(choice1);
            cout << endl; // For better spacing, good looking and organized UI
            while(restart){
                restart = 0;
                user->logSign(choice2);
                delete user;
                cout << endl; // For better spacing, good looking and organized UI
                // Deciding which user role to give
                if(choice1 == 1){
                    user = new Staff();
                    if(choice2 == 2){
                        // staff SIGNUP
                        user->signUP(choice1);
                    }else if(choice2 == 1){
                        // staff LOGIN
                        user->login(choice1, notLogin);
                    }else{
                        if(choice2 != 3){
                            cout << "Incorrect Input! Only 1 to 3 is accepted. Please try again!" << endl;
                        }
                        delete user;
                        backMainMenu = 1;
                    }
                }else if(choice1 == 2){
                    user = new Customer();
                    if(choice2 == 2){
                        // customer SIGNUP
                        user->signUP(choice1);
                    }else if(choice2 == 1){
                        // customer LOGIN
                        user->login(choice1, notLogin);
                    }else{
                        if(choice2 != 3){
                            cout << "Incorrect Input! Only 1 to 3 is accepted. Please try again!" << endl;
                        }
                        delete user;
                        backMainMenu = 1;
                    }
                }else{
                    // Input validation
                    cout << "Incorrect Input! Only 1 or 2 is accepted. Please try again!" << endl;
                    delete user;
                    backMainMenu = 1;
                }
                if((choice1 == 1 || choice1 == 2) && choice2 == 1){
                    while(notLogin == 1){ // User has correct username but wrong password
                        user->login(choice1, notLogin);
                    }
                    if(notLogin == 2){ // User doesn't have any account or record, ask them to sign up
                        // Wrong username and password. Ask if wanna login again or signup.
                        cout << "Wrong username and password. Please choose to login again or sign up for a new account." << endl;
                        cout << endl;
                        delete user;
                        restart = 1;
                    }
                }
            }
        }
        cout << endl;
        cout << "Continue? (y/n): ";
        cin >> cont;
    }
    return 0;
}