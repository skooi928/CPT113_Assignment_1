#include <iostream>
#include <fstream>
#include "user.h"
#include "service.h"
#include "pastry.h"
#include "rating.h"
#include "receipt.h"
using namespace std;

// No default constructor is allowed, since there must be no user without username and password.
// Constructor, to create user object, so they can access to the program.
User :: User(string userN, string pw, string r){
    username = userN;
    password = pw;
    role = r;
}

// Login function
void User :: login(bool &notLogin){
    // Check if the provided credentials match user's credentials
    notLogin = 1;
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
            break;
        }
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
        while(userdata >> userN >> pw){
            if(newUsername == userN){
                cout << "This username has been used! Please try a new one." << endl;
            }else if(newUsername == userN && newPassword == pw){
                cout << "This account has already existed. Please go to login!" << endl;
                noAccount = 0;
            }else{
                // Save new user information to a text file
                fstream userdata((role + ".txt"), ios::app);
                if (!userdata) {
                    cout << "Error: Unable to open file." << endl;
                }else{
                    // Writing the data to respective .txt file
                    userdata << newUsername << " " << newPassword << endl;
                    cout << "User signed up successfully." << endl;
                    userdata.close();
                }
                cout << "Your account is successfully created." << endl;
                noAccount = 0;
            }
        }
    }
}

Staff :: Staff(string userN, string pw) : User(userN, pw, "staff"){};

Customer :: Customer(string userN, string pw) : User(userN, pw, "customer"){};