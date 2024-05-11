#include <iostream>
#include <fstream>
#include "user.h"
#include "service.h"
#include "pastry.h"
#include "rating.h"
#include "receipt.h"
using namespace std;

// Default constructor
User :: User(){
    username = "";
    password = "";
    role = "";
}

// Login function
void User :: login(int r, int &notLogin){
    // Check if the provided credentials match user's credentials
    if(r == 1){
        role = "staff";
    }else if(r == 2){
        role = "customer";
    }

    // Get username and pw
    string inputUsername;
    string inputPassword;
    cout << "Enter Your Username: ";
    cin >> inputUsername;
    cout << "Enter Your Password: ";
    cin >> inputPassword;
    username = inputUsername;
    password = inputPassword;

    notLogin = 2;
    fstream staffFile;
    staffFile.open((role + ".txt"), ios::in);
    string userN, pw;
    while(staffFile >> userN >> pw){
        if(username == userN && password == pw){
            cout << "You have login successfully. Welcome " << username << "!" << endl;
            notLogin = 0;
            break;
        }else if(username == userN && password != pw){
            cout << "Wrong password! Please try again!" << endl;
            cout << endl;
            notLogin = 1;
            break;
        }
    }
    if(notLogin == 2){
        cout << "Your account is not found!" << endl;
        cout << "Please sign up here: " << endl;
        cout << endl;
    }
}

// Sign up function
void User :: signUP(int r){
    // Set the role
    if(r == 1){
        role = "staff";
    }else if(r == 2){
        role = "customer";
    }

    bool noAccount = 1;
    // Loop until an account has been created
    while(noAccount){
        string newUsername, newPassword;
        // Get the username and password from the user
        cout << "Enter new username: ";
        cin >> newUsername;
        cout << "Enter new password: ";
        cin >> newPassword;
        
        // Check if it is already in the database
        fstream userdata((role + ".txt"), ios::in);
        string userN, pw;
        if(!(userdata >> userN)){
            fstream userdata((role + ".txt"), ios::app);
            // Writing the data to respective .txt file
            userdata << newUsername << " " << newPassword << endl;
            cout << "User signed up successfully." << endl;
            userdata.close();
            cout << "Your account is successfully created." << endl;
            noAccount = 0;
        }else{
            bool notSame = 1; // to track if the new username is unique or not
            fstream userdata((role + ".txt"), ios::in);
            while(userdata >> userN >> pw){
                if(newUsername == userN){
                    cout << "ERROR! This username has been used! Please try a new one." << endl;
                    cout << endl;
                    notSame = 0;
                    break;
                }
            }
            if(notSame){
                // Save new user information to a text file
                fstream userdata((role + ".txt"), ios::app);
                if (!userdata) {
                    cout << "Error: Unable to open file." << endl;
                }else{
                    // Writing the data to respective .txt file
                    userdata << newUsername << " " << newPassword << endl;
                    userdata.close();
                    cout << "User signed up successfully." << endl;
                    cout << "Your account is successfully created." << endl;
                }
                noAccount = 0;
            }
        }
    }
}

void User :: logOut(User* user){
    cout << "You have successfully logged out!" << endl;
    delete user;
}

Staff :: Staff() : User(){};

Customer :: Customer() : User(){};